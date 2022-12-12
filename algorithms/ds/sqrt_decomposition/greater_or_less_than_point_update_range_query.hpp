
/**
 * \brief Defines a class for a data structure build with sqrt decomposition to efficiently obtain amount of values greater (or smaller)
 *        than a dynamic value.
 *        State: tested.
 *        Ref: https://cp-algorithms.com/data_structures/sqrt_decomposition.html
 *
 * \details Build: O(MaxSize * log2(BlockSize)) -> using BlockSize = sqrt(MaxSize): O(MaxSize * log2(sqrt(MaxSize))
 *          Query: O(MaxSize / BlockSize * log2(BlockSize)) -> using BlockSize = sqrt(MaxSize): O(sqrt(MaxSize) * log2(sqrt(MaxSize))
 *          Update: O(BlockSize) -> using BlockSize = sqrt(MaxSize): O(sqrt(MaxSize))
 *
 * \tparam ValueType Type of the elements.
 * \tparam MaxSize Maximum number of elements.
 * \tparam BlockSize Size of the blocks (sometimes sqrt(MaxSize) is not optimal).
 * \tparam ElementCompare Comparator function to use (std::less, std::less_equal, std::greater, std::greater_equal).
 */
template<typename ValueType, int MaxSize, int BlockSize, typename ElementCompare>
class SqrtDecompositionGreaterOrLessThanPointUpdateRangeQuery {
private:
	int numBlocks;
	ValueType n, a[MaxSize], sorted[MaxSize / BlockSize + 1][BlockSize], sortedSize[MaxSize / BlockSize + 1];
	ElementCompare elementCompare;

	void buildBlock(int blockId) {
		int l = blockId * BlockSize;
		int r = std::min(l + BlockSize - 1, n);

		std::copy(a + l, a + r + 1, sorted[blockId]);
		sortedSize[blockId] = r - l + 1;
		std::sort(sorted[blockId], sorted[blockId] + sortedSize[blockId], elementCompare);
	}

	void rebuildBlock(int blockId, ValueType oldVal, ValueType newVal) {
		auto idx = std::distance(sorted[blockId], std::lower_bound(sorted[blockId], sorted[blockId] + BlockSize, oldVal, elementCompare));
		if (sorted[blockId][idx] != oldVal) idx--;
		sorted[blockId][idx] = newVal;

		while (idx + 1 < sortedSize[blockId] && !elementCompare(sorted[blockId][idx], sorted[blockId][idx + 1])) {
			std::swap(sorted[blockId][idx], sorted[blockId][idx + 1]);
			idx++;
		}
		while (idx > 0 && !elementCompare(sorted[blockId][idx - 1], sorted[blockId][idx])) {
			std::swap(sorted[blockId][idx - 1], sorted[blockId][idx]);
			idx--;
		}
	}

public:

	void init(int size, ValueType* arr) {
		n = size;
		std::copy(arr, arr + n, a);
		for (int i = 0, end = ceil(n / BlockSize); i <= end; i++) buildBlock(i);
	}

	int count(int l, int r, int val) {
		int blockL = l / BlockSize;
		int blockR = r / BlockSize;
		int ans = 0;

		if (blockL == blockR) {
			if (r - l + 1 == sortedSize[blockL]) {
				ans += std::distance(sorted[blockL],
				                     std::lower_bound(sorted[blockL], sorted[blockL] + sortedSize[blockL], val, elementCompare));
			} else for (int i = l; i <= r; i++) if (elementCompare(a[i], val)) ans++;
		} else {
			if (l % BlockSize) {
				for (int i = l, end = (blockL + 1) * BlockSize - 1; i <= end; i++) if (elementCompare(a[i], val)) ans++;
				blockL++;
			}
			for (int i = blockR * BlockSize; i <= r; i++) if (elementCompare(a[i], val)) ans++;
			for (int blockId = blockL; blockId <= blockR - 1; blockId++) {
				ans += std::distance(sorted[blockId],
				                     std::lower_bound(sorted[blockId], sorted[blockId] + sortedSize[blockId], val, elementCompare));
			}
		}
		return ans;
	}

	void update(int idx, ValueType val) {
		rebuildBlock(idx / BlockSize, a[idx], val);
		a[idx] = val;
	}
};

template<typename ValueType, int MaxSize, int BlockSize>
using SqrtDecompositionGreaterThanPointUpdateRangeQuery =
		SqrtDecompositionGreaterOrLessThanPointUpdateRangeQuery<ValueType, MaxSize, BlockSize, std::greater<ValueType>>;

template<typename ValueType, int MaxSize, int BlockSize>
using SqrtDecompositionGreaterEqualThanPointUpdateRangeQuery =
		SqrtDecompositionGreaterOrLessThanPointUpdateRangeQuery<ValueType, MaxSize, BlockSize, std::greater_equal<ValueType>>;

template<typename ValueType, int MaxSize, int BlockSize>
using SqrtDecompositionLessThanPointUpdateRangeQuery =
		SqrtDecompositionGreaterOrLessThanPointUpdateRangeQuery<ValueType, MaxSize, BlockSize, std::less<ValueType>>;

template<typename ValueType, int MaxSize, int BlockSize>
using SqrtDecompositionLessEqualThanPointUpdateRangeQuery =
		SqrtDecompositionGreaterOrLessThanPointUpdateRangeQuery<ValueType, MaxSize, BlockSize, std::less_equal<ValueType>>;
