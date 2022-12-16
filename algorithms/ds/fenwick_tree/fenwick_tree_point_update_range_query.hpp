
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
