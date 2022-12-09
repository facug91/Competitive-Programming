
/**
 * \brief Defines a class for a Fenwick Tree 3D (Binary Indexed Tree 3D).
 *        State: tested.
 *        Ref: Competitive Programming 3, section 2.4.4
 *             https://cp-algorithms.com/data_structures/fenwick.html
 *             https://www.geeksforgeeks.org/binary-indexed-tree-range-update-range-queries/
 *
 * \tparam ValueType Type of the elements.
 * \tparam MaxDim1 Maximum size of the first dimension.
 * \tparam MaxDim2 Maximum size of the second dimension (MaxDim1 by default).
 * \tparam MaxDim3 Maximum size of the third dimension (MaxDim2 by default).
 */
template<typename ValueType, int MaxDim1, int MaxDim2 = MaxDim1, int MaxDim3 = MaxDim2>
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
