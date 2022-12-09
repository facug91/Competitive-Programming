/*
        By: facug91
        From: https://www.spoj.com/problems/TRIPINV/
        Name: Mega Inversions
        Date: 05/12/2022
        Solution: Fenwick Tree
*/

#include <bits/stdc++.h>

/**
 * \brief Defines a class for a Fenwick Tree (Binary Indexed Tree).
 *        State: tested.
 *        Ref: Competitive Programming 3, section 2.4.4
 *             https://cp-algorithms.com/data_structures/fenwick.html
 *             https://www.geeksforgeeks.org/binary-indexed-tree-range-update-range-queries/
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
		memset(bit, 0, sizeof(ValueType) * n);
	}

	void init(int size, ValueType val) {
		init(size);
		for (size_t i = 0; i < size; i++) add(i, val);
	}

	void init(int size, ValueType* arr) {
		init(size);
		for (size_t i = 0; i < size; i++) add(i, arr[i]);
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

const int MAX_N = 1e5 + 5;
const int MAX_Q = 1e5 + 5;
const int MOD = 1e9 + 7;

ll n, arr[MAX_N], ans;
FenwickTreePointUpdateRangeQuery<ll, MAX_N> ft1, ft2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	ft1.init(n + 1);
	ft2.init(n + 1);
	ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		ll smallest1 = ft1.sum(arr[i] - 1);
		if (smallest1 > 0) {
			ll smallest2 = ft2.sum(arr[i] - 1);
			ans += smallest2;
			ft2.add(arr[i], smallest1);
		}
		ft1.add(arr[i], 1);
	}
	cout << ans << endline;

	return 0;
}
