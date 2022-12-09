
/**
 * Sparse table for range min/max query.
 * Ref: Competitive Programming 3, section 9.33
 *      https://cp-algorithms.com/data_structures/sparse-table.html
 */

/**
 * \brief Defines a class for a sparse table for range min/max query.
 *
 * \tparam ValueType Type of the elements.
 * \tparam MaxSize Maximum number of elements.
 * \tparam MaxSizeLog Log2 of MaxSize rounded down (i.e. std::floor(std::log2(MaxSize)).
 * \tparam ElementCompare Comparator function to use (std::less by default, for a range minimum query sparse table).
 * \tparam PositionCompare Comparator function for the indexes of the elements (std::less by default, to choose the leftmost value).
 */
template<typename ValueType, int MaxSize, int MaxSizeLog, typename ElementCompare = std::less<ValueType>, typename PositionCompare = std::less<int>>
class SparseTableRMQ {
private:
	int n, k;
	ElementCompare elementCompare;
	PositionCompare positionCompare;
	ValueType st[MaxSizeLog + 1][MaxSize];
	ValueType arr[MaxSize];

#if __cplusplus >= 202002L
	int log2_floor(ValueType i) {
		return std::bit_width(i) - 1;
	}
#else

	int log2_floor(ValueType i) {
		return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
	}

#endif

	// Invert comparison operators if you need a range max query sparse table
	// Replace std::min with std::max if you need the rightmost index instead of the leftmost
	int calcIndex(int i, int j) {
		if (elementCompare(arr[i], arr[j])) return i;
		if (!elementCompare(arr[i], arr[j])) return j;
		return positionCompare(i, j) ? i : j;
	}

	void calcSparseTable() {
		for (int i = 0; i < n; i++) st[0][i] = i;
		for (int i = 1; i <= k; i++)
			for (int j = 0; j + (1 << i) <= n; j++)
				st[i][j] = calcIndex(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
	}

public:

	void setNewArray(ValueType* begin, ValueType* end) {
		std::copy(begin, end, arr);
		n = std::distance(begin, end);
		k = log2_floor(n);
		calcSparseTable();
	}

	void setNewArray(typename std::vector<ValueType>::iterator begin, typename std::vector<ValueType>::iterator end) {
		std::copy(begin, end, arr);
		n = std::distance(begin, end);
		k = log2_floor(n);
		calcSparseTable();
	}

	void setNewArray(std::vector<ValueType>& newArray) {
		setNewArray(newArray.begin(), newArray.end());
	}

	void setNewArray(ValueType* newArray, int size) {
		setNewArray(newArray, newArray + size);
	}

	int queryIndex(int l, int r) {
		auto i = log2_floor(r - l + 1);
		return calcIndex(st[i][l], st[i][r - (1 << i) + 1]);
	}

	ValueType queryValue(int l, int r) {
		return arr[queryIndex(l, r)];
	}
};
