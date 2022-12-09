/*
        By: facug91
        From: https://www.spoj.com/problems/KOPC12G/
        Name: K12-Bored of Suffixes and Prefixes
        Date: 05/12/2022
        Solution: Fenwick Tree 2D
*/

#include <bits/stdc++.h>

/**
 * \brief Defines a class for a Fenwick Tree 2D (Binary Indexed Tree 2D).
 *        State: tested.
 *        Ref: Competitive Programming 3, section 2.4.4
 *             https://cp-algorithms.com/data_structures/fenwick.html
 *             https://www.geeksforgeeks.org/binary-indexed-tree-range-update-range-queries/
 *
 * \tparam ValueType Type of the elements.
 * \tparam MaxRows Maximum number of rows.
 * \tparam MaxCols Maximum number of columns (MaxRows by default).
 */
template<typename ValueType, int MaxRows, int MaxCols = MaxRows>
class FenwickTree2DPointUpdateRangeQuery {
private:
	int n, m;
	ValueType bit[MaxRows + 1][MaxCols + 1];

public:

	void init(int rows, int cols) {
		n = rows + 1;
		m = cols + 1;
		for (int i = 0; i < n; i++)
			memset(bit[i], 0, sizeof(ValueType) * m);
	}

	void init(int size) {
		init(size, size);
	}

	void add(int row, int col, ValueType delta) {
		for (int i = row + 1; i < n; i += i & -i)
			for (int j = col + 1; j < m; j += j & -j)
				bit[i][j] += delta;
	}

	ValueType sum(int row, int col) {
		ValueType ret = 0;
		for (int i = row + 1; i > 0; i -= i & -i)
			for (int j = col + 1; j > 0; j -= j & -j)
				ret += bit[i][j];
		return ret;
	}

	ValueType sum(int bottomRow, int leftCol, int topRow, int rightCol) {
		return sum(topRow, rightCol) - sum(topRow, leftCol - 1) - sum(bottomRow - 1, rightCol) + sum(bottomRow - 1, leftCol - 1);
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

const int MAX_N = 5e2 + 5;
const int MAX_Q = 1e5 + 5;
const int MOD = 1e9 + 7;

int t, n, q, type, x1, y1, x2, y2;
string mat[MAX_N], line;
FenwickTree2DPointUpdateRangeQuery<int, MAX_N> ft;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	while (t--) {
		cin >> n >> q;
		ft.init(n);
		for (int i = 0; i < n; i++) {
			cin >> mat[i];
			for (int j = 0; j < n; j++)
				ft.add(i, j, mat[i][j] - 'A' + 1);
		}
		while (q--) {
			cin >> type;
			if (type == 0) {
				cin >> x1 >> y1 >> line;
				if (x1 == 0)
					for (int j = 0; j < n; j++) {
						ft.add(y1, j, line[j] - 'A' - (mat[y1][j] - 'A'));
						mat[y1][j] = line[j];
					}
				else
					for (int i = 0; i < n; i++) {
						ft.add(i, y1, line[i] - 'A' - (mat[i][y1] - 'A'));
						mat[i][y1] = line[i];
					}
			} else {
				cin >> x1 >> y1 >> x2 >> y2;
				cout << ft.sum(x1, y1, x2, y2) << endline;
			}
		}
	}

	return 0;
}
