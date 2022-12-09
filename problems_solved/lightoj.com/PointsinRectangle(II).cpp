/*
        By: facug91
        From: https://lightoj.com/problem/points-in-rectangle
        Name: Points in Rectangle
        Date: 01/12/2022
*/

#include <bits/stdc++.h>

/**
 * \brief Defines a class for a Fenwick Tree 2D (Binary Indexed Tree 2D).
 *        State: tested.
 *
 * \tparam ValueType Type of the elements.
 * \tparam MaxRows Maximum number of rows.
 * \tparam MaxCols Maximum number of columns.
 */
template<typename ValueType, int MaxRows, int MaxCols>
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

	void init(int rows, int cols, ValueType** mat) {
		init(rows, cols);
		for (size_t i = 0; i < rows; i++)
			for (size_t j = 0; j < cols; j++)
				add(i, j, mat[i][j]);
	}

	void init(std::vector<std::vector<ValueType>>& mat) {
		init(mat.size(), mat[0].size());
		for (size_t i = 0; i < mat.size(); i++)
			for (size_t j = 0; j < mat[i].size(); j++)
				add(i, j, mat[i][j]);
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
#define endline std::endl;
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

const int MAX_N = 1e3 + 5;
const int MAX_K = 16;
const int MOD = 1e9 + 7;

int t, q, type, x1, y1, x2, y2;
FenwickTree2DPointUpdateRangeQuery<int, MAX_N, MAX_N> ft;
bool listed[MAX_N][MAX_N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	for (int it = 1; it <= t; it++) {
		ft.init(MAX_N, MAX_N);
		memset(listed, 0, sizeof(listed));
		cout << "Case " << it << ":" << endline;
		cin >> q;
		while (q--) {
			cin >> type;
			if (type == 0) {
				cin >> x1 >> y1;
				x1++; y1++;
				if (!listed[x1][y1]) {
					ft.add(x1, y1, 1);
					listed[x1][y1] = true;
				}
			} else /* if (type == 1) */ {
				cin >> x1 >> y1 >> x2 >> y2;
				x1++; y1++; x2++; y2++;
				cout << ft.sum(x1, y1, x2, y2) << endline;
			}
		}
	}


	return 0;
}
