/*
        By: facug91
        From: https://www.spoj.com/problems/CONSEC/
        Name: Consecutive Letters
        Date: 29/11/2022
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
using namespace std;

#ifdef DEBUG
#define endline std::endl;
#define LOG(x) std::cout << "#" << (#x) << ": " << (x) << std::endl
#else
#define endline "\n"
#define LOG(x)
#endif

const double EPS = 1e-9;
const double PI = 2.0 * acos(0.0);
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int MAX_N = 2e5 + 5;
const int MAX_K = 16;
const int MOD = 1e9 + 7;

int t, q, a[MAX_N], b[MAX_N], ans[MAX_N];
string s1, s2;
UFDS<MAX_N> uf;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	for (int it = 1; it <= t; it++) {
		cin >> s1;
		s2 = s1;

		cin >> q;
		for (int iq = 0; iq < q; iq++) {
			cin >> a[iq] >> b[iq];
			if (a[iq] == 2) s2[b[iq]] = '#';
		}

		uf.init(s2.length());
		for (int i = 1; i < s2.length(); i++)
			if (s2[i] != '#' && s2[i - 1] == s2[i])
				uf.unionSet(i - 1, i);

		for (int iq = q - 1; iq >= 0; iq--) {
			auto bi = b[iq];
			if (a[iq] == 1) {
				ans[iq] = uf.sizeOfSet(bi);
			} else /* if (a[iq] == 2) */ {
				s2[bi] = s1[bi];
				if (bi > 0 && s2[bi - 1] == s2[bi]) uf.unionSet(bi - 1, bi);
				if (bi + 1 < s2.length() && s2[bi + 1] == s2[bi]) uf.unionSet(bi + 1, bi);
			}
		}

		cout << "Case " << it << ":" << endline;
		for (int iq = 0; iq < q; iq++)
			if (a[iq] == 1)
				cout << ans[iq] << endline;
	}


	return 0;
}
