/*
        By: facug91
        From: https://www.spoj.com/problems/SGIFT/
        Name: Sabbir and gifts
        Date: 03/12/2022
        Solution: RSQ + binary search
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
#define endline std::endl
#define LOG(x) std::cout << "#" << (#x) << ": " << (x) << std::endl
#else
#define endline "\n"
#define LOG(x)
#endif

#define y0 dbnw9uddu0132dnd03dnqwuidg1o
#define y1 nd03dnqwuidg1odbnw9uddu0132d
const double EPS = 1e-9;
const double PI = 2.0 * acos(0.0);
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

const int MAX_N = 1e5 + 5;
const int MAX_Q = 1e5 + 5;
const int MOD = 1e9 + 7;

int n, p, q, a, b;
map<int, ll> RSQ;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> p, RSQ[p] += p;

	RSQ[-1] = 0;
	for (auto itr = next(RSQ.begin()); itr != RSQ.end(); itr++)
		itr->second += prev(itr)->second;

	cin >> q;
	while (q--) {
		cin >> a >> b;
		cout << prev(RSQ.upper_bound(b))->second - prev(RSQ.lower_bound(a))->second << endline;
	}


	return 0;
}
