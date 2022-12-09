/*
        By: facug91
        From: https://www.spoj.com/problems/ZIGZAG2/
        Name: Zig when you zag
        Date: 04/12/2022
        Solution: Fenwick Tree 2D
*/

#include <bits/stdc++.h>

/**
 * \brief Defines a class for a Fenwick Tree 2D (Binary Indexed Tree 2D) for Min/Max value.
 *        State: tested.
 *        Ref: Competitive Programming 3, section 2.4.4
 *             https://cp-algorithms.com/data_structures/fenwick.html
 *             https://www.geeksforgeeks.org/binary-indexed-tree-range-update-range-queries/
 *
 * \tparam ValueType Type of the elements.
 * \tparam MaxRows Maximum number of rows.
 * \tparam MaxCols Maximum number of columns.
 * \tparam ElementCompare Comparator function to use (std::less by default, for a range minimum query).
 * \tparam LimitValue Limit value, used for initialization (std::numeric_limits<ValueType>::max() by default).
 */
template<typename ValueType, int MaxRows, int MaxCols, typename ElementCompare = std::less<ValueType>, ValueType LimitValue = std::numeric_limits<ValueType>::max()>
class FenwickTree2DMinMax {
private:
	int n, m;
	ValueType bit[MaxRows + 1][MaxCols + 1];
	ElementCompare elementCompare;

public:

	ValueType Limit = LimitValue;

	void init(int rows, int cols) {
		n = rows + 1;
		m = cols + 1;
		for (int i = 0; i < n; i++)
			std::fill(bit[i], bit[i] + m, LimitValue);
	}

	void init(int size) {
		init(size, size);
	}

	void update(int row, int col, ValueType val) {
		for (int i = row + 1; i < n; i += i & -i)
			for (int j = col + 1; j < m; j += j & -j)
				bit[i][j] = elementCompare(bit[i][j], val) ? bit[i][j] : val;
	}

	ValueType getValue(int row, int col) {
		ValueType ret = LimitValue;
		for (int i = row + 1; i > 0; i -= i & -i)
			for (int j = col + 1; j > 0; j -= j & -j)
				ret = elementCompare(bit[i][j], ret) ? bit[i][j] : ret;
		return ret;
	}
};

template<typename ValueType, int MaxRows, int MaxCols>
using FenwickTree2DMin = FenwickTree2DMinMax<ValueType, MaxRows, MaxCols>;

template<typename ValueType, int MaxRows, int MaxCols>
using FenwickTree2DMax = FenwickTree2DMinMax<ValueType, MaxRows, MaxCols, std::greater<ValueType>, std::numeric_limits<ValueType>::min()>;

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

const int MAX_N = 2e3 + 5;
const int MAX_Q = 1e5 + 5;
const int MOD = 1e9 + 7;

int t, n, a[MAX_N], m, b[MAX_N], c[MAX_N], ans;
map<int, int> compressValue, counterA, counterB;
FenwickTree2DMax<int, MAX_N, MAX_N> ftFromHigher;
FenwickTree2DMax<int, MAX_N, MAX_N> ftFromSmaller;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		cin >> m;
		for (int j = 1; j <= m; j++) cin >> b[j];

		copy(b + 1, b + m + 1, c);
		sort(c, c + m);

		int idx = 0;
		compressValue[c[0]] = idx++;
		for (int i = 1; i < m; i++)
			if (c[i] != c[i - 1])
				compressValue[c[i]] = idx++;

		ftFromHigher.init(max(n, m) + 1);
		ftFromSmaller.init(max(n, m) + 1);


		ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (a[i] == b[j]) {
					{
						auto aux = max(ftFromHigher.getValue(j, compressValue[b[j]] - 1), 0);
						ans = max(ans, aux + 1);
						ftFromSmaller.update(j, idx - compressValue[b[j]], aux + 1);
					}
					{
						auto aux = max(ftFromSmaller.getValue(j, idx - (compressValue[b[j]] + 1)), 0);
						ans = max(ans, aux + 1);
						ftFromHigher.update(j, compressValue[b[j]], aux + 1);
					}
				}
			}
		}

		if (ans == 1) {
			for (int i = 1; i <= n; i++) counterA[a[i]]++;
			for (int j = 1; j <= m; j++) counterB[b[j]]++;
			for (auto p: counterA) {
				if (p.second > 1 && counterB[p.first] > 1) {
					ans = 2;
					break;
				}
			}
		}

		cout << ans << endline;

	}

	return 0;
}
