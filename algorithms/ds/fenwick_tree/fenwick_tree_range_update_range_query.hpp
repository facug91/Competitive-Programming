
/**
 * \brief Defines a class for a Fenwick Tree (Binary Indexed Tree).
 *        State: untested.
 *        Ref: Competitive Programming 3, section 2.4.4
 *             https://cp-algorithms.com/data_structures/fenwick.html
 *             https://www.geeksforgeeks.org/binary-indexed-tree-range-update-range-queries/
 *
 * \tparam ValueType Type of the elements.
 * \tparam MaxSize Maximum number of elements.
 */
template<typename ValueType, int MaxSize>
class FenwickTreeRangeUpdateRangeQuery {
private:

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
			for (size_t i = 0; i < size; i++) add(i, val);
		}

		void init(int size, ValueType* arr) {
			init(size);
			for (size_t i = 0; i < size; i++) add(i, arr[i]);
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

	FenwickTreePointUpdateRangeQuery B1, B2;

public:

	void init(int size) {
		B1.init(size);
		B2.init(size);
	}

	void range_add(int l, int r, ValueType x) {
		B1.add(l, x);
		B1.add(r + 1, -x);
		B2.add(l, x * (l - 1));
		B2.add(r + 1, -x * r);
	}

	ValueType sum(int r) {
		return B1.sum(r) * r - B2.sum(r); // TODO : check if r is ok
	}

	ValueType range_sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
};
