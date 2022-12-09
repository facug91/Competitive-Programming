/*
        By: facug91
        From: https://www.spoj.com/problems/ADABEHIVE/
        Name: Ada and Behives
        Date: 02/12/2022
        Solution: Fenwick Tree 2D
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
const int MAX_A = 1e6 + 5;
const int MAX_Q = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, m, q, type, x1, y1, x2, y2, val;
vector<vector<long long>> mat;
FenwickTree2DPointUpdateRangeQuery<long long, MAX_N, MAX_N> ft;
map<string, int> s1ToIndex;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m >> q;
	mat.resize(n);
	for (int i = 0; i < n; i++) {
		mat[i].resize(m);
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	ft.init(mat);

	while (q--) {
		cin >> type;
		if (type == 1) {
			cin >> x1 >> y1 >> val;
			ft.add(x1 - 1, y1 - 1, val);
		} else /* if (type == 2) */ {
			cin >> x1 >> y1 >> x2 >> y2;
			cout << ft.sum(x1 - 1, y1 - 1, x2 - 1, y2 - 1) << endline;
		}
	}

	return 0;
}
