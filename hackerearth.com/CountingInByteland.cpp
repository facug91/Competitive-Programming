/*
        By: facug91
        From: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/counting-in-byteland/
        Name: Counting In Byteland
        Date: 02/12/2022
        Solution: Fenwick Tree 3D
*/

#include <bits/stdc++.h>

/**
 * \brief Defines a class for a Fenwick Tree 3D (Binary Indexed Tree 3D).
 *        State: tested.
 *
 * \tparam ValueType Type of the elements.
 * \tparam MaxDim1 Maximum size of the first dimension.
 * \tparam MaxDim2 Maximum size of the second dimension.
 * \tparam MaxDim3 Maximum size of the third dimension.
 */
template<typename ValueType, int MaxDim1, int MaxDim2, int MaxDim3>
class FenwickTree3DPointUpdateRangeQuery {
private:
	int d1, d2, d3;
	ValueType bit[MaxDim1 + 1][MaxDim2 + 1][MaxDim3 + 1];

public:

	void init(int dim1, int dim2, int dim3) {
		d1 = dim1 + 1;
		d2 = dim2 + 1;
		d3 = dim3 + 1;
		for (int i = 0; i < d1; i++)
			for (int j = 0; j < d2; j++)
				memset(bit[i][j], 0, sizeof(ValueType) * d3);
	}

	void init(int dim1, int dim2, int dim3, ValueType** mat) {
		init(dim1, dim2, dim3);
		for (size_t i = 0; i < dim1; i++)
			for (size_t j = 0; j < dim2; j++)
				for (size_t k = 0; k < dim3; k++)
					add(i, j, k, mat[i][j][k]);
	}

	void init(std::vector<std::vector<std::vector<ValueType>>>& mat) {
		init(mat.size(), mat[0].size(), mat[0][0].size());
		for (size_t i = 0; i < mat.size(); i++)
			for (size_t j = 0; j < mat[i].size(); j++)
				for (size_t k = 0; k < mat[i][j].size(); k++)
					add(i, j, k, mat[i][j][k]);
	}

	void add(int x, int y, int z, ValueType delta) {
		for (int i = x + 1; i < d1; i += i & -i)
			for (int j = y + 1; j < d2; j += j & -j)
				for (int k = z + 1; k < d3; k += k & -k)
					bit[i][j][k] += delta;
	}

	ValueType sum(int x, int y, int z) {
		ValueType ret = 0;
		for (int i = x + 1; i > 0; i -= i & -i)
			for (int j = y + 1; j > 0; j -= j & -j)
				for (int k = z + 1; k > 0; k -= k & -k)
					ret += bit[i][j][k];
		return ret;
	}

	ValueType sum(int x1, int y1, int z1, int x2, int y2, int z2) {
		auto val1 = sum(x2, y2, z2) - sum(x1 - 1, y2, z2) - sum(x2, y1 - 1, z2) + sum(x1 - 1, y1 - 1, z2);
		auto val2 = sum(x2, y2, z1 - 1) - sum(x1 - 1, y2, z1 - 1) - sum(x2, y1 - 1, z1 - 1) + sum(x1 - 1, y1 - 1, z1 - 1);
		return val1 - val2;
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

const int MAX_N = 1e2 + 5;
const int MAX_A = 1e6 + 5;
const int MAX_Q = 2e5 + 5;
const int MOD = 1e9 + 7;

int n, q, type, x1, y1, z1, x2, y2, z2, val;
FenwickTree3DPointUpdateRangeQuery<long long, MAX_N, MAX_N, MAX_N> ft;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> q;
	ft.init(n + 1, n + 1, n + 1);
	while (q--) {
		cin >> type;
		if (type == 1) {
			cin >> x1 >> y1 >> z1 >> val;
			ft.add(x1, y1, z1, val);
		} else /* if (type == 2) */ {
			cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
			cout << ft.sum(n, n, n) - ft.sum(x1, y1, z1, x2, y2, z2) << endline;
		}
	}

	return 0;
}
