/*
        By: facug91
        From: https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/lexicographically-minimal-string-6edc1406/
        Name: Lexicographically minimal string
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
		if (x < y) {
			p[y] = x;
		} else {
			p[x] = y;
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

string a, b, c;
UFDS<MAX_N> uf;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> a >> b >> c;
	uf.init(30);
	for (int i = 0; i < a.length(); i++)
		uf.unionSet(a[i] - 'a', b[i] - 'a');
	for (int i = 0; i < c.length(); i++)
		c[i] = char(uf.findSet(c[i] - 'a') + 'a');
	cout << c << endline;


	return 0;
}
