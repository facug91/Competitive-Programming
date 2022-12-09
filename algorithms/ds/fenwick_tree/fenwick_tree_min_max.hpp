
/**
 * \brief Defines a class for a Fenwick Tree (Binary Indexed Tree) for Min/Max value.
 *        State: tested.
 *        Ref: Competitive Programming 3, section 2.4.4
 *             https://cp-algorithms.com/data_structures/fenwick.html
 *             https://www.geeksforgeeks.org/binary-indexed-tree-range-update-range-queries/
 *
 * \tparam ValueType Type of the elements.
 * \tparam MaxSize Maximum number of elements.
 * \tparam ElementCompare Comparator function to use (std::less by default, for a range minimum query).
 * \tparam LimitValue Limit value, used for initialization (std::numeric_limits<ValueType>::max() by default).
 */
template<typename ValueType, int MaxSize, typename ElementCompare = std::less<ValueType>, ValueType LimitValue = std::numeric_limits<ValueType>::max()>
class FenwickTreeMinMax {
private:
	int n;
	ValueType bit[MaxSize + 1];
	ElementCompare elementCompare;

public:

	ValueType Limit = LimitValue;

	void init(int size) {
		n = size + 1;
		std::fill(bit, bit + n, LimitValue);
	}

	void init(int size, ValueType* arr) {
		init(size);
		for (size_t i = 0; i < size; i++)
			update(i, arr[i]);
	}

	void init(std::vector<ValueType>& arr) {
		init(arr.size(), &arr[0]);
	}

	void update(int idx, ValueType val) {
		for (++idx; idx < n; idx += idx & -idx)
			bit[idx] = elementCompare(bit[idx], val) ? bit[idx] : val;
	}

	ValueType getValue(int r) {
		ValueType ret = LimitValue;
		for (++r; r > 0; r -= r & -r)
			ret = elementCompare(bit[r], ret) ? bit[r] : ret;
		return ret;
	}
};

template<typename ValueType, int MaxSize>
using FenwickTreeMin = FenwickTreeMinMax<ValueType, MaxSize>;

template<typename ValueType, int MaxSize>
using FenwickTreeMax = FenwickTreeMinMax<ValueType, MaxSize, std::greater<ValueType>, std::numeric_limits<ValueType>::min()>;
