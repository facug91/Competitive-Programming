/**
 * \brief Defines a class for a Union-Find Disjoint Sets.
 *        Ref: https://cp-algorithms.com/data_structures/disjoint_set_union.html
 *
 * \tparam MaxSize Maximum number of elements.
 */
template<int MaxSize>
class UFDS {
private:
	int p[MaxSize], rank[MaxSize], counter[MaxSize], numDisjointSets;

public:
	void init(int n) {
		std::fill(rank, rank + n, 0);
		std::fill(counter, counter + n, 1);
		for (int i = 0; i < n; i++) p[i] = i;
		numDisjointSets = n;
	}

	int findSet(int i) {
		if (p[i] == i) return i;
		return p[i] = findSet(p[i]);
	}

	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j) {
		int x = findSet(i);
		int y = findSet(j);
		if (x != y) {
			numDisjointSets--;
			if (rank[x] > rank[y]) {
				p[y] = x;
				counter[x] += counter[y];
			} else {
				p[x] = y;
				counter[y] += counter[x];
				if (rank[x] == rank[y])
					rank[y]++;
			}
		}
	}

	int sizeOfSet(int i) {
		return counter[findSet(i)];
	}

	int getNumDisjointSets() {
		return numDisjointSets;
	}
};