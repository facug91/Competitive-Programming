/*
        By: facug91
        From: https://www.codechef.com/problems/BINLAND
        Name: Binary Land
        Date: 27/11/2022
*/

#include <bits/stdc++.h>

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

int n, q, c, d, DP[21][300001][21], top, bottom, middle, ans;
string op, a[300001];

inline void calcRow(int i, int j, int move) {
	for (int k = 0; k < n; k++) {
		DP[i][j][k] = 0;
		if (a[j][k] == a[j + move][k]) DP[i][j][k] = DP[i][j + move][k];
		if (k - 1 >= 0 && a[j][k] == a[j + move][k - 1]) DP[i][j][k] = (DP[i][j][k] + DP[i][j + move][k - 1]) % MOD;
		if (k + 1 < n && a[j][k] == a[j + move][k + 1]) DP[i][j][k] = (DP[i][j][k] + DP[i][j + move][k + 1]) % MOD;
	}
}

void dp() {
	for (int i = 0; i < n; i++) {
		fill(DP[i][middle], DP[i][middle] + n, 0);
		DP[i][middle][i] = 1;
		for (int j = middle - 1; j >= top; j--)
			calcRow(i, j, 1);
		for (int j = middle + 1; j <= bottom; j++)
			calcRow(i, j, -1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> q;
	top = 0, bottom = -1;
	middle = -1;
	for (int i = 0; i < q; i++) {
		cin >> op;
		if (op[0] == 'a') {
			bottom++;
			cin >> a[bottom];
			if (bottom - top + 1 == 3) {
				middle = bottom - 1;
				dp();
			}
			if (bottom - top + 1 >= 3)
				for (int j = 0; j < n; j++)
					calcRow(j, bottom, -1);
		} else if (op[0] == 'r') {
			top++;
			if (top == middle) {
				if (bottom - top + 1 >= 3) {
					middle = bottom - 1;
					dp();
				}
			}
		} else /* if (op[0] == 'p') */ {
			cin >> c >> d;
			c--;
			d--;
			ans = 0;
			if (bottom - top + 1 == 1)
				ans = (c == d) ? 1 : 0;
			if (bottom - top + 1 == 2)
				ans = (a[top][c] == a[bottom][d] && abs(d - c) <= 1) ? 1 : 0;
			if (bottom - top + 1 >= 3) {
				for (int j = 0; j < n; j++)
					ans = (ans + (ll)DP[j][top][c] * (ll)DP[j][bottom][d]) % MOD;
			}
			cout << ans << endline;
		}
	}

	return 0;
}
