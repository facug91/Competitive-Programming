/*
        By: facug91
        From: https://toph.co/p/unbelievable-array
        Name: Unbelievable Array
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
			p[y] = x;
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

const int MAX_N = 1e5 + 5;
const int MAX_K = 16;
const int MOD = 1e9 + 7;

int t, n, q, c, type, x, y, idx, colorToIndex[MAX_N], indexToColor[MAX_N];
UFDS<MAX_N> uf;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	for (int it = 1; it <= t; it++) {
		cin >> n >> q;
		uf.init(n);
		fill(colorToIndex, colorToIndex + MAX_N, -1);
		for (int i = 0; i < n; i++) {
			cin >> c;
			if (colorToIndex[c] == -1) {
				colorToIndex[c] = i;
				indexToColor[i] = c;
			} else {
				uf.unionSet(colorToIndex[c], i);
			}
		}

		cout << "Case " << it << ":" << endline;
		while (q--) {
			cin >> type;
			if (type == 1) {
				cin >> x >> y;
				if (x == y) continue;
				if (colorToIndex[x] == -1) continue;
				if (colorToIndex[y] == -1) {
					indexToColor[colorToIndex[x]] = y;
					colorToIndex[y] = colorToIndex[x];
					colorToIndex[x] = -1;
				} else {
					uf.unionSet(colorToIndex[y], colorToIndex[x]);
					colorToIndex[x] = -1;
				}
			} else {
				cin >> idx;
				idx--;
				cout << indexToColor[uf.findSet(idx)] << endline;
			}
		}
	}
	return 0;
}
