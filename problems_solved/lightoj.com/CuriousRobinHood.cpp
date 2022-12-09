/*
        By: facug91
        From: https://lightoj.com/problem/curious-robin-hood
        Name: Curious Robin Hood
        Date: 01/12/2022
*/

#include <bits/stdc++.h>

/**
 * \brief Defines a class for a Fenwick Tree (Binary Indexed Tree).
 *
 * \tparam ValueType Type of the elements.
 * \tparam MaxSize Maximum number of elements.
 */
template<typename ValueType, int MaxSize>
class FenwickTreePointUpdateRangeQuery {
private:
	int n;
	ValueType bit[MaxSize + 1];

public:

	void init(int size) {
		n = size + 1;
		std::fill(bit, bit + n, 0);
	}

	void init(int size, ValueType* arr) {
		init(size);
		for (size_t i = 0; i < size; i++)
			add(i, arr[i]);
	}

	void init(std::vector<ValueType>& arr) {
		init(arr.size(), &arr[0]);
	}

	void add(int idx, ValueType delta) {
		for (++idx; idx < n; idx += idx & -idx)
			bit[idx] += delta;
	}

	ValueType sum(int r) {
		ValueType ret = 0;
		for (++r; r > 0; r -= r & -r)
			ret += bit[r];
		return ret;
	}

	ValueType sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
};

using namespace std;

#ifdef DEBUG
#define endline std::endl;
#define LOG(x) std::cout << "#" << (#x) << ": " << (x) << std::endl
#else
#define endline "\n"
#define LOG(x)
#endif

const double EPS = 1e-9;
const double PI = 2.0 * acos(0.0);
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int MAX_N = 1e5 + 5;
const int MAX_K = 16;
const int MOD = 1e9 + 7;

int t, n, q, type, idx, v, l, r, arr[MAX_N];
FenwickTreePointUpdateRangeQuery<int, MAX_N> ft;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	for (int it = 1; it <= t; it++) {
		cin >> n >> q;
		for (int i = 0; i < n; i++) cin >> arr[i];
		ft.init(n, arr);
		cout << "Case " << it << ":" << endline;
		while (q--) {
			cin >> type;
			if (type == 1) {
				cin >> idx;
				auto aux = ft.sum(idx, idx);
				cout << aux << endline;
				ft.add(idx, -aux);
			} else if (type == 2) {
				cin >> idx >> v;
				ft.add(idx, v);
			} else /* if (type == 3) */ {
				cin >> l >> r;
				cout << ft.sum(l, r) << endline;
			}
		}
	}

	return 0;
}
