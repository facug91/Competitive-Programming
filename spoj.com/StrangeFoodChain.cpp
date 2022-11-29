/*
        By: facug91
        From: https://www.spoj.com/problems/CHAIN/
        Name: Strange Food Chain
        Date: 28/11/2022
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
public:
	int p[MaxSize], dis[MaxSize], n;

public:
	void init(int n) {
		this->n = n;
		for (int i = 0; i < n; i++) p[i] = i, dis[i] = 0;
	}

	int findSet(int i) {
		if (p[i] == i) return i;
		auto up = p[i];
		p[i] = findSet(p[i]);
		dis[i] = (dis[i] + dis[up]) % 3;
		return p[i];
	}

	bool unionSet(int i, int j, int d) {
		if (i >= n || j >= n) return false;
		int x = findSet(i);
		int y = findSet(j);
		if (x != y) {
			p[y] = x;
			dis[y] = ((dis[i] - dis[j] - d) % 3 + 3) % 3;
			return true;
		} else {
			return ((dis[i] - dis[j]) % 3 + 3) % 3 == d;
		}
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
typedef long long ll;

const int MAX_N = 5e4 + 5;
const int MAX_K = 16;
const int MOD = 1e9 + 7;

int t, n, k, d, x, y, px, py, ans;
UFDS<MAX_N> uf;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	for (int it = 1; it <= t; it++) {
		cin >> n >> k;
		uf.init(n);
		ans = 0;
		for (int ik = 1; ik <= k; ik++) {
			cin >> d >> x >> y;
			d--;
			x--;
			y--;
			if (!uf.unionSet(x, y, d)) ans++;
		}
		cout << ans << endline;
	}

	return 0;
}
