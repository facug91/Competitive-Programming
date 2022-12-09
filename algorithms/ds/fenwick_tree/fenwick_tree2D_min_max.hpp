
/**
 * \brief Defines a class for a Fenwick Tree 2D (Binary Indexed Tree 2D) for Min/Max value.
 *        State: tested.
 *        Ref: Competitive Programming 3, section 2.4.4
 *             https://cp-algorithms.com/data_structures/fenwick.html
 *             https://www.geeksforgeeks.org/binary-indexed-tree-range-update-range-queries/
 *
 * \tparam ValueType Type of the elements.
 * \tparam MaxRows Maximum number of rows.
 * \tparam MaxCols Maximum number of columns (MaxRows by default).
 * \tparam ElementCompare Comparator function to use (std::less by default, for a range minimum query).
 * \tparam LimitValue Limit value, used for initialization (std::numeric_limits<ValueType>::max() by default).
 */
template<typename ValueType, int MaxRows, int MaxCols = MaxRows, typename ElementCompare = std::less<ValueType>, ValueType LimitValue = std::numeric_limits<ValueType>::max()>
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

template<typename ValueType, int MaxRows, int MaxCols = MaxRows>
using FenwickTree2DMin = FenwickTree2DMinMax<ValueType, MaxRows, MaxCols>;

template<typename ValueType, int MaxRows, int MaxCols = MaxRows>
using FenwickTree2DMax = FenwickTree2DMinMax<ValueType, MaxRows, MaxCols, std::greater<ValueType>, std::numeric_limits<ValueType>::min()>;
