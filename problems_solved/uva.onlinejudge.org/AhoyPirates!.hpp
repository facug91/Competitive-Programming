/*
        By: facug91
        From: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2397
        Name: 11402 - Ahoy, Pirates!
        Date: 20/12/2022
        Solution: segment tree with lazy propagation
*/

#include <bits/stdc++.h>

template<typename ValueType, int MaxSize>
class SegmentTreeRangeUpdateRangeQuery {
private:
	int n;
	ValueType st[MaxSize * 4];
	ValueType lazyUpdate[MaxSize * 4];
	ValueType lazyAdd[MaxSize * 4];
	ValueType defaultValue = 0;

	ValueType combine(ValueType a, ValueType b) { return a + b; }

	void build(ValueType arr[], int v, int tl, int tr) {
		lazyUpdate[v] = -1;
		lazyAdd[v] = 0;
		if (tl == tr) st[v] = arr[tl];
		else {
			int tm = (tl + tr) / 2;
			build(arr, v * 2, tl, tm);
			build(arr, v * 2 + 1, tm + 1, tr);
			st[v] = combine(st[v * 2], st[v * 2 + 1]);
		}
	}

	void push(int v, int tl, int tr) {
		int tm = (tl + tr) / 2;
		if (lazyUpdate[v] != -1) {
			st[v * 2] = lazyUpdate[v] * (tm - tl + 1);
			lazyUpdate[v * 2] = lazyUpdate[v];
			lazyAdd[v * 2] = 0;
			st[v * 2 + 1] = lazyUpdate[v] * (tr - tm);
			lazyUpdate[v * 2 + 1] = lazyUpdate[v];
			lazyAdd[v * 2 + 1] = 0;
			lazyUpdate[v] = -1;
		}
		if (lazyAdd[v] != 0) {
			st[v * 2] = tm - tl + 1 - st[v * 2];
			lazyAdd[v * 2] = (lazyAdd[v * 2] + lazyAdd[v]) % 2;
			st[v * 2 + 1] = tr - tm - st[v * 2 + 1];
			lazyAdd[v * 2 + 1] = (lazyAdd[v * 2 + 1] + lazyAdd[v]) % 2;
			lazyAdd[v] = 0;
		}
		assert(st[v] == st[v * 2] + st[v * 2 + 1]);
	}

	ValueType query(int v, int tl, int tr, int l, int r) {
		if (l > r) return defaultValue;
		if (l == tl && r == tr) return st[v];
		push(v, tl, tr);
		int tm = (tl + tr) / 2;
		return combine(query(v * 2, tl, tm, l, std::min(r, tm)),
		               query(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r));
	}

	void update(int v, int tl, int tr, int l, int r, ValueType val) {
		if (l > r) return;
		if (l == tl && r == tr) {
			st[v] = (tr - tl + 1) * val;
			lazyUpdate[v] = val;
			lazyAdd[v] = 0;
		} else {
			push(v, tl, tr);

			int tm = (tl + tr) / 2;
			update(v * 2, tl, tm, l, std::min(r, tm), val);
			update(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r, val);
			st[v] = combine(st[v * 2], st[v * 2 + 1]);
		}
	}

	void add(int v, int tl, int tr, int l, int r, ValueType val) {
		if (l > r) return;
		if (l == tl && r == tr) {
			st[v] = (tr - tl + 1) - st[v];
			lazyAdd[v] = (lazyAdd[v] + val) % 2;
		} else {
			push(v, tl, tr);

			int tm = (tl + tr) / 2;
			add(v * 2, tl, tm, l, std::min(r, tm), val);
			add(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r, val);
			st[v] = combine(st[v * 2], st[v * 2 + 1]);
		}
	}

public:

	void build(int size, ValueType* arr) {
		n = size;
		build(arr, 1, 0, size - 1);
	}

	ValueType query(int l, int r) {
		return query(1, 0, n - 1, l, r);
	}

	void update(int l, int r, ValueType val) {
		update(1, 0, n - 1, l, r, val);
	}

	void add(int l, int r, ValueType val) {
		add(1, 0, n - 1, l, r, val);
	}
};

using namespace std;

#ifdef DEBUG
#define endline std::endl
#define LOG(x) std::cout << "#" << (#x) << ": " << (x) << std::endl
#else
#define endline "\n"
#define LOG(x)
#endif

#define y0 dbnw9uddu0132dnd03dnqwuidg1o
#define y1 nd03dnqwuidg1odbnw9uddu0132d
const double EPS = 1e-9;
const double PI = 2.0 * acos(0.0);
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

const int MAX_N = 1024005;
const int MAX_A = 1e6 + 5;
const int MAX_Q = 2e5 + 5;
const int MOD = 1e9 + 7;

int t, m, n, segmentTimes, p[MAX_N], q, a, b;
string line;

SegmentTreeRangeUpdateRangeQuery<int, MAX_N> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	for (int it = 1; it <= t; it++) {
		cout << "Case " << it << ":" << endline;
		cin >> m;
		n = 0;
		for (int i = 0; i < m; i++) {
			cin >> segmentTimes >> line;
			for (int j = 0; j < segmentTimes; j++)
				for (int k = 0; k < line.size(); k++)
					p[n++] = line[k] - '0';
		}
		st.build(n, p);
		cin >> q;
		int iq = 1;
		while (q--) {
			cin>>line>>a>>b;
			if (line[0] == 'F') {
				st.update(a, b, 1);
			} else if (line[0] == 'E') {
				st.update(a, b, 0);
			} else if (line[0] == 'I') {
				st.add(a, b, 1);
			} else if (line[0] == 'S') {
				cout << "Q" << iq++ << ": " << st.query(a, b) << endline;
			}
		}
	}

	return 0;
}
