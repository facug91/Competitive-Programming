/*
        By: facug91
        From: https://www.codechef.com/problems/SPREAD
        Name: Gravel
        Date: 01/12/2022
*/

#include <bits/stdc++.h>

/**
 * \brief Defines a class for a Fenwick Tree (Binary Indexed Tree).
 *        State: untested.
 *
 * \tparam ValueType Type of the elements.
 * \tparam MaxSize Maximum number of elements.
 */
template<typename ValueType, int MaxSize>
class FenwickTreeRangeUpdatePointQuery {
private:
	int n;
	ValueType bit[MaxSize + 2];

	void add(int idx, ValueType delta) {
		for (++idx; idx < n; idx += idx & -idx)
			bit[idx] += delta;
	}

public:

	void init(int size) {
		n = size + 2;
		memset(bit, 0, sizeof(ValueType) * n);
	}

	void range_add(int l, int r, ValueType val) {
		add(l, val);
		add(r + 1, -val);
	}

	ValueType point_query(int idx) {
		ValueType ret = 0;
		for (++idx; idx > 0; idx -= idx & -idx)
			ret += bit[idx];
		return ret;
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

const int MAX_N = 1e6 + 5;
const int MAX_K = 16;
const int MOD = 1e9 + 7;

int n, m, c, u, v, k, p, arr[MAX_N];
string type;
FenwickTreeRangeUpdatePointQuery<long long, MAX_N> ft;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> c;
	ft.init(n);
	ft.range_add(0, n, c);

	while (m--) {
		cin >> type;
		if (type[0] == 'S') {
			cin >> u >> v >> k;
			u--; v--;
			ft.range_add(u, v, k);
		} else /* if (type[0] == 'Q') */ {
			cin >> p;
			p--;
			cout << ft.point_query(p) << endline;
		}
	}


	return 0;
}
