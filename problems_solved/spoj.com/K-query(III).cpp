/*
        By: facug91
        From: http://www.spoj.com/problems/KQUERY/
        Name: K-query
        Date: 18/12/2022
        Solution: Fenwick Tree + Sorting
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
		bit[0] = 0;
		std::fill(bit + 1, bit + size + 1, val);
		for (size_t i = 0; i < size; i++) {
			size_t j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
	}

	void init(int size, ValueType* arr) {
		init(size);
		bit[0] = 0;
		std::copy(arr, arr + size, bit + 1);
		for (size_t i = 0; i < size; i++) {
			size_t j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
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

const int MAX_N = 3e4 + 5;
const int MAX_A = 1e6 + 5;
const int MAX_Q = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, m, a, l, r, k, ans[MAX_Q];
pair<ii, ii> queries[MAX_Q];
ii val[MAX_N];

FenwickTreePointUpdateRangeQuery<int, MAX_N> ft;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		val[i].first = a;
		val[i].second = i;
	}
	sort(val, val + n);
	ft.init(n, 1);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> l >> r >> k;
		queries[i].first.first = k;
		queries[i].first.second = i;
		queries[i].second.first = l - 1;
		queries[i].second.second = r - 1;
	}
	sort(queries, queries + m);
	int curr = 0;
	for (int i = 0; i < m; i++) {
		while (curr < n && val[curr].first <= queries[i].first.first) ft.add(val[curr++].second, -1);
		ans[queries[i].first.second] = ft.sum(queries[i].second.first, queries[i].second.second);
	}
	for (int i = 0; i < m; i++) cout << ans[i] << endline;

	return 0;
}
