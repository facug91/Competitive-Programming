
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
class FenwickTreeRangeUpdatePointQuery {
private:
	int n;
	ValueType bit[MaxSize + 2];

	void add(int idx, ValueType delta) {
		for (++idx; idx < n; idx += idx & -idx)
			bit[idx] += delta;
	}

public:

	void init(int size) {
		n = size + 2;
		memset(bit, 0, sizeof(ValueType) * n);
	}

	void range_add(int l, int r, ValueType val) {
		add(l, val);
		add(r + 1, -val);
	}

	ValueType point_query(int idx) {
		ValueType ret = 0;
		for (++idx; idx > 0; idx -= idx & -idx)
			ret += bit[idx];
		return ret;
	}
};
