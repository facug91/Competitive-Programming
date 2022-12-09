/*
        By: facug91
        From: https://acm.timus.ru/problem.aspx?space=1&num=1003
        Name: Parity
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

struct query {
	int l, r;
	string s;
};

int n, m, l, r, freeIndex, ans;
string s;
UFDS<20005> uf;
unordered_map<int, int> seqToIndex;
vector<query> questions;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while (cin >> n, n != -1) {
		cin >> m;
		questions.resize(m);
		for (int i = 0; i < m; i++)
			cin >> questions[i].l >> questions[i].r >> questions[i].s;

		freeIndex = ans = 0;
		uf.init(m * 2 * 2);
		seqToIndex.clear();
		bool stop = false;

		for (int i = 0; i < m; i++) {
			l = questions[i].l - 1;
			r = questions[i].r;
			s = questions[i].s;

			if (!seqToIndex.contains(r)) seqToIndex.insert({ r, freeIndex++ });
			if (!seqToIndex.contains(l)) seqToIndex.insert({ l, freeIndex++ });
			if (s[0] == 'e') {
				uf.unionSet(seqToIndex[r] * 2, seqToIndex[l] * 2);
				uf.unionSet(seqToIndex[r] * 2 + 1, seqToIndex[l] * 2 + 1);
			} else {
				uf.unionSet(seqToIndex[r] * 2, seqToIndex[l] * 2 + 1);
				uf.unionSet(seqToIndex[r] * 2 + 1, seqToIndex[l] * 2);
			}
			for (int j = 0; j < freeIndex; j++)
				if (uf.isSameSet(j * 2, j * 2 + 1)) {
					stop = true;
					break;
				}
			if (stop) break;
			ans++;
		}
		cout << ans << endline;
	}

	return 0;
}
