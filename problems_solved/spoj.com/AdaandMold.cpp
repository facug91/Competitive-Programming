/*
        By: facug91
        From: https://www.spoj.com/problems/ADAMOLD/
        Name: ADAMOLD - Ada and Mold
        Date: 08/01/2023
        Solution: DP + D&C
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

template<typename T>
T fastMod(const T input, const T ceil) {
	// apply the modulo operator only when needed
	// (i.e. when the input is greater than the ceiling)
	return input >= ceil ? input % ceil : input;
	// NB: the assumption here is that the numbers are positive
}

#define y0 dbnw9uddu0132dnd03dnqwuidg1o
#define y1 nd03dnqwuidg1odbnw9uddu0132d
const double EPS = 1e-9;
const double PI = 2.0 * acos(0.0);
using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;

const int MAX_N = 5e3 + 5;
const int MAX_Q = 1e5 + 5;
const int MOD = 1e9 + 7;

ll n, s, a[MAX_N], onesRSQ[MAX_N][30], DP[MAX_N][MAX_N], DPWS[MAX_N][MAX_N];

void dp(int seg, int l, int r, int optL, int optR) {
	if (l > r) return;

	int mid = (l + r) / 2, optIdx;
	ll optValue = std::numeric_limits<ll>::max();
	for (int i = optL, end = min(optR, mid); i <= end; i++) {
		ll aux = DPWS[seg - 1][i] + ((i == n) ? 0 : DP[i + 1][mid]);
		if (optValue > aux) {
			optValue = aux;
			optIdx = i;
		}
	}

	DPWS[seg][mid] = optValue;
	dp(seg, l, mid - 1, optL, optIdx);
	dp(seg, mid + 1, r, optIdx, optR);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> s;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int j = 0; j < 30; j++) onesRSQ[0][j] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 30; j++)
			onesRSQ[i][j] = onesRSQ[i - 1][j] + ((a[i] & (1 << j)) != 0);

	for (int i = 0; i <= n; i++) DP[i][0] = DP[0][i] = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++) {
			DP[i][j] = DP[i][j - 1];
			for (int k = 0; k < 30; k++)
				if ((a[j] & (1 << k)) == 0) DP[i][j] += ((onesRSQ[j - 1][k] - onesRSQ[i - 1][k]) * (1 << k));
				else DP[i][j] += ((j - i - (onesRSQ[j - 1][k] - onesRSQ[i - 1][k])) * (1 << k));
		}

	for (int i = 0; i <= n; i++) DPWS[0][i] = DP[1][i];
	for (int i = 1; i <= s; i++)
		dp(i, 0, n, 0, n);

	cout << DPWS[s][n] << endline;

	return 0;
}
