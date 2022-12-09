/*
        By: facug91
        From: https://acm.timus.ru/problem.aspx?space=1&num=1671
        Name: Anansi's Cobweb
        Date: 27/11/2022
*/

#include <bits/stdc++.h>

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
		return findSet(p[i]);
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
				counter[x]++;
			} else {
				p[x] = y;
				counter[y]++;
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

using namespace std;

#ifdef DEBUG
#define endline std::endl;
#define LOG(x) std::cerr << "#" << (#x) << ": " << (x) << std::endl
#else
#define endline "\n"
#define LOG(x)
#endif

const double EPS = 1e-9;
const double PI = 2.0 * acos(0.0);
typedef long long ll;

const int MAX_N = 1e5 + 5;
const int MAX_K = 16;
const int MOD = 1e9 + 7;

int n, m, q, destroy2[MAX_N], ans[MAX_N];
pair<int, int> threads[MAX_N];
UFDS<MAX_N> uf;
set<int> notDestroy;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	uf.init(n);
	for (int i = 0; i < m; i++) {
		cin >> threads[i].first >> threads[i].second;
		threads[i].first--;
		threads[i].second--;
		notDestroy.insert(i);
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> destroy2[i];
		destroy2[i]--;
		notDestroy.erase(destroy2[i]);
	}
	for (auto d: notDestroy)
		uf.unionSet(threads[d].first, threads[d].second);
	for (int i = q - 1; i >= 0; i--) {
		ans[i] = uf.getNumDisjointSets();
		uf.unionSet(threads[destroy2[i]].first, threads[destroy2[i]].second);
	}
	for (int i=0; i<q; i++) {
		if (i != 0) cout << " ";
		cout << ans[i];
	}
	cout << endline;


	return 0;
}
