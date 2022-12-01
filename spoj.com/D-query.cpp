/*
        By: facug91
        From: https://www.spoj.com/problems/DQUERY/
        Name: D-query
        Date: 01/12/2022
        Solution: sorting + Fenwick Tree
*/

#include <bits/stdc++.h>

/**
 * \brief Defines a class for a Fenwick Tree (Binary Indexed Tree).
 *        State: tested.
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

const int MAX_N = 3e4 + 5;
const int MAX_A = 1e6 + 5;
const int MAX_Q = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, arr[MAX_N], q, l, r, lastUsed[MAX_A], ans[MAX_Q];
pair<int, pair<int, int>> queries[MAX_Q];
FenwickTreePointUpdateRangeQuery<int, MAX_N> ft;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> l >> r;
		l--;
		r--;
		queries[i] = { r, { l, i }};
	}
	sort(queries, queries + q);

	fill(lastUsed, lastUsed + MAX_A, -1);
	ft.init(n);

	int iq = 0;
	for (int i = 0; i < n; i++) {
		if (lastUsed[arr[i]] != -1)
			ft.add(lastUsed[arr[i]], -1);
		ft.add(i, 1);
		lastUsed[arr[i]] = i;
		while (iq < q && queries[iq].first == i) {
			r = queries[iq].first;
			l = queries[iq].second.first;
			int idx = queries[iq].second.second;
			ans[idx] = ft.sum(l, r);
			iq++;
		}
	}

	for (int i = 0; i < q; i++)
		cout << ans[i] << endline;

	return 0;
}
