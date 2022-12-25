/*
        By: facug91
        From: https://www.spoj.com/problems/GSS3/
        Name: GSS3 - Can you answer these queries III
        Date: 20/12/2022
        Solution: Segment tree
*/

#include <bits/stdc++.h>

/**
 * \brief Defines a class for a Segment Tree.
 *        State: untested.
 *        Ref: Competitive Programming 3, section 2.4.3
 *             https://cp-algorithms.com/data_structures/segment_tree.html
 *
 * \tparam ValueType Type of the elements.
 * \tparam MaxSize Maximum number of elements.
 * \tparam ElementCompare Comparator function to combine intervals and partial answers
 *         (e.g. struct SumCombine { ValueType operator()(ValueType val1, ValueType val2) { return val1 + val2; }};).
 * \tparam DefaultValueFunc Function returning the default value, used when calling with an undefined interval (l > r)
 *         (e.g. struct SumDefaultValue { ValueType operator()() { return 0; }};).
 */
template<typename ValueType, int MaxSize, typename CombineFunc, typename DefaultValueFunc>
class SegmentTreePointUpdateRangeQuery {
private:
	int n;
	ValueType st[MaxSize * 4];
	CombineFunc combine;
	DefaultValueFunc defaultValueFunc;

	void build(ValueType arr[], int v, int tl, int tr) {
		if (tl == tr) st[v] = arr[tl];
		else {
			int tm = (tl + tr) / 2;
			build(arr, v * 2, tl, tm);
			build(arr, v * 2 + 1, tm + 1, tr);
			st[v] = combine(st[v * 2], st[v * 2 + 1]);
		}
	}

	ValueType query(int v, int tl, int tr, int l, int r) {
		if (l > r) return defaultValueFunc();
		if (l == tl && r == tr) return st[v];

		int tm = (tl + tr) / 2;
		return combine(query(v * 2, tl, tm, l, std::min(r, tm)),
		               query(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r));
	}

	void update(int v, int tl, int tr, int pos, ValueType val) {
		if (tl == tr) st[v] = val;
		else {
			int tm = (tl + tr) / 2;
			if (pos <= tm) update(v * 2, tl, tm, pos, val);
			else update(v * 2 + 1, tm + 1, tr, pos, val);
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

	void update(int idx, ValueType val) {
		update(1, 0, n - 1, idx, val);
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

const int MAX_N = 5e4 + 5;
const int MAX_A = 1e6 + 5;
const int MAX_Q = 2e5 + 5;
const int MOD = 1e9 + 7;

struct Data {
	int sum, prefix, suffix, ans;
	Data() = default;
	Data(int sum, int prefix, int suffix, int ans) : sum(sum), prefix(prefix), suffix(suffix), ans(ans) {}
};
const auto invalid = std::numeric_limits<int>::min();
struct MaxSumCombinePURQ {
	Data operator()(const Data& l, const Data& r) {
		if (l.ans == invalid) return r;
		if (r.ans == invalid) return l;
		Data res;
		res.sum = l.sum + r.sum;
		res.prefix = max(l.prefix, l.sum + r.prefix);
		res.suffix = max(r.suffix, r.sum + l.suffix);
		res.ans = max(max(l.ans, r.ans), l.suffix + r.prefix);
		return res;
	}
};
struct MaxSumDefaultValuePURQ { Data operator()() { return Data(invalid, invalid, invalid, invalid); }};

int n, m, type, x, y;
Data a[MAX_N];
SegmentTreePointUpdateRangeQuery<Data, MAX_N, MaxSumCombinePURQ, MaxSumDefaultValuePURQ> st;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].sum;
		a[i].prefix = a[i].suffix = a[i].ans = a[i].sum;
	}
	st.build(n, a);

	cin >> m;
	while (m--) {
		cin >> type >> x >> y;
		if (type == 0) st.update(x - 1, Data(y, y, y, y));
		else cout << st.query(x - 1, y - 1).ans << endline;
	}

	return 0;
}
