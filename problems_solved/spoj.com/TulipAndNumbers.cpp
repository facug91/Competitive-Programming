/*
        By: facug91
        From: https://www.spoj.com/problems/TULIPNUM/
        Name: Tulip And Numbers
        Date: 02/12/2022
        Solution: rsq
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
const int MAX_A = 1e6 + 5;
const int MAX_Q = 2e5 + 5;
const int MOD = 1e9 + 7;

int t, n, q, l, r, arr[MAX_N], rsq[MAX_N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> t;
	for (int it = 1; it <= t; it++) {
		cin >> n >> q;

		arr[0] = -1;
		for (int i = 1; i <= n; i++) cin >> arr[i];

		rsq[0] = 0;
		for (int i = 1; i <= n; i++) {
			rsq[i] = rsq[i-1];
			if (arr[i] != arr[i - 1]) rsq[i] = rsq[i-1] + 1;
		}

		cout << "Case " << it << ":" << endline;
		while (q--) {
			cin >> l >> r;
			cout << rsq[r] - rsq[l-1] + (rsq[l] == rsq[l-1]) << endline;
		}
	}

	return 0;
}
