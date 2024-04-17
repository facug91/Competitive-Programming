/*
        By: facug91
        From: https://www.spoj.com/problems/LARMY/
        Name: LARMY - Lannister Army
        Date: 08/01/2023
        Solution: Fenwick Tree + DP + D&C
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

template<typename T>
T fastMod(const T input, const T ceil) {
	// apply the modulo operator only when needed
	// (i.e. when the input is greater than the ceiling)
	return input >= ceil ? input % ceil : input;
	// NB: the assumption here is that the numbers are positive
}

#define y0 dbnw9uddu0132dnd03dnqwuidg1o
#define y1 nd03dnqwuidg1odbnw9uddu0132d
const double EPS = 1e-9;
const double PI = 2.0 * acos(0.0);
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

const int MAX_N = 5e3 + 5;
const int MAX_Q = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, k, h[MAX_N], DP[MAX_N][MAX_N], DP2[MAX_N][MAX_N];
FenwickTreePointUpdateRangeQuery<int, MAX_N> ft;
set<int> numbers;
map<int, int> compress;

void dp(int level, int l, int r, int optL, int optR) {
	if (l > r) return;

	int mid = (l + r) / 2, optValue = std::numeric_limits<int>::max(), optIdx;
	for (int i = optL, end = min(optR, mid); i <= end; i++) {
		int aux = DP2[level - 1][i] + (i == n ? 0 : DP[i + 1][mid]);
		if (aux < optValue) {
			optValue = aux;
			optIdx = i;
		}
	}

	DP2[level][mid] = optValue;
	dp(level, l, mid - 1, optL, optIdx);
	dp(level, mid + 1, r, optIdx, optR);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> h[i], numbers.insert(h[i]);

	int idx = 1;
	for (auto number: numbers) compress.emplace(make_pair(number, idx++));
	for (int i = 1; i <= n; i++) h[i] = compress[h[i]];

	for (int i = 0; i <= n; i++) DP[i][0] = DP[0][i] = 0;
	for (int i = 1; i <= n; i++) {
		ft.init(numbers.size() + 1);
		ft.add(h[i], 1);
		DP[i][i] = 0;
		for (int j = i + 1; j <= n; j++) {
			DP[i][j] = DP[i][j - 1] + (j - i - ft.sum(h[j]));
			ft.add(h[j], 1);
		}
	}

	for (int i = 0; i <= n; i++) DP2[0][i] = DP[1][i];
	for (int i = 1; i <= k; i++)
		dp(i, 1, n, 1, n);

	cout << DP2[k-1][n] << endline;

	return 0;
}
