/*
        By: facug91
        From: https://www.spoj.com/problems/SUMSUM/
        Name: Enjoy Sum with Operations
        Date: 02/12/2022
        Solution: Fenwick Tree + bitwise
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
const int MAX_B = 27;
const int MAX_Q = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, q, type, idx, l, r;
ll arr[MAX_N], val, ones, zeros, ans;
string op;
FenwickTreePointUpdateRangeQuery<ll, MAX_N> ft[MAX_B];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < MAX_B; i++) {
		ft[i].init(n);
		for (int j = 0; j < n; j++) {
			if ((arr[j] & (1 << i)) != 0) {
				ft[i].add(j, 1);
			}
		}
	}

	while (q--) {
		cin >> type;
		if (type == 1) {
			cin >> val >> idx;
			idx--;
			for (int i = 0; i < MAX_B; i++) {
				ll oldBit = arr[idx] & (1ll << i);
				ll newBit = val & (1ll << i);
				if (oldBit != newBit)
					ft[i].add(idx, (oldBit != 0ll) ? -1ll : 1ll);
			}
			arr[idx] = val;
		} else /* if (type == 2) */ {
			cin >> op >> l >> r;
			l--;
			r--;
			ans = 0;
			if (op[0] == 'X') {
				for (int i = 0; i < MAX_B; i++) {
					ones = ft[i].sum(l, r);
					zeros = r - l + 1 - ones;
					ans += ones * zeros * (1 << i);
				}
			} else if (op[0] == 'O') {
				for (int i = 0; i < MAX_B; i++) {
					ones = ft[i].sum(l, r);
					zeros = r - l + 1ll - ones;
					ans += ones * (ones - 1ll) / 2ll * (1ll << i);
					ans += ones * zeros * (1ll << i);
				}
			} else /* if (op[0] == 'A') */ {
				for (int i = 0; i < MAX_B; i++) {
					ones = ft[i].sum(l, r);
					ans += ones * (ones - 1ll) / 2ll * (1ll << i);
				}
			}
			cout << ans << endline;
		}
	}

	return 0;
}
