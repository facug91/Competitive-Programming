/*
        By: facug91
        From: https://www.spoj.com/problems/CLFLARR/
        Name: COLORFUL ARRAY
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
	int p[MaxSize];

public:
	void init(int n) {
		for (int i = 0; i < n; i++) p[i] = i;
	}

	int findSet(int i) {
		if (p[i] == i) return i;
		return p[i] = findSet(p[i]);
	}

	void unionSet(int i, int j) {
		int x = findSet(i);
		int y = findSet(j);
		if (x != y) {
			p[x] = p[y] = std::max(x, y);
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
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;

const int MAX_N = 2e5 + 5;
const int MAX_K = 16;
const int MOD = 1e9 + 7;

int n, q, l[MAX_N], r[MAX_N], c[MAX_N], ans[MAX_N];
UFDS<MAX_N> uf;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> q;
	uf.init(n+5);
	memset(ans, 0, sizeof(ans));
	for (int iq = 0; iq < q; iq++) {
		cin >> l[iq] >> r[iq] >> c[iq];
		l[iq]--;
		r[iq]--;
	}

	for (int iq = q-1; iq >= 0; iq--) {
		for (int i = uf.findSet(l[iq]); i <= r[iq]; i = uf.findSet(i + 1)) {
			ans[i] = c[iq];
			uf.unionSet(i, i + 1);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << endline;
	}

	return 0;
}
