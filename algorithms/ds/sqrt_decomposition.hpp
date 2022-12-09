
#include <bits/stdc++.h>

template<typename ValueType, int MaxSize, int BlockSize>
class SqrtDecompositionRSQ {
private:
	int numBlocks;
	ValueType a, block[MaxSize / BlockSize + 1];
public:

	void init(int size, ValueType* arr) {
		std::copy(arr, arr + size, a);
		numBlocks = (int)std::ceil(size / BlockSize);
		for (int i = 0; i < numBlocks; i++) {
			block[i] = a[i * BlockSize];
			for (int j = i * BlockSize, endJ = std::min((i + 1) * BlockSize, size); j < endJ; j++)
				block[i] += a[j];
		}
	}

	ValueType query(int l, int r) {
		ValueType ans = 0;
		int blockL = l / BlockSize;
		int blockR = r / BlockSize;
		if (blockL == blockR) {
			for (int i = l; i <= r; i++) ans += a[i];
		} else {
			if (l % BlockSize) {
				for (int i = l, end = (blockL + 1) * BlockSize - 1; i <= end; i++) ans += a[i];
				blockL++;
			}
			for (int i = blockR * BlockSize; i <= r; i++) ans += a[i];
			for (int blockId = blockL; blockId < blockR; blockId++) ans += block[blockId];
		}
		return ans;
	}

	void update(int idx, ValueType val) {
		block[idx/BlockSize] += (val - a[idx]);
		a[idx] = val;
	}

};