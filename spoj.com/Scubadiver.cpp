/*
        By: facug91
        From: http://www.spoj.com/problems/SCUBADIV/
        Name: Scuba diver
        Number: 181
        Date: 26/08/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN N

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int t, a, n, DP[1001][44][160];
pair<ii, int> cyl[1001];

int dp (int idx, int oxi, int nit) {
	if (idx == n) return INF;
	if (DP[idx][oxi][nit] != -1) return DP[idx][oxi][nit];
	int oxi2 = oxi - cyl[idx].first.first;
	int nit2 = nit - cyl[idx].first.second;
	if (oxi2 <= 22 && nit2 <= 80) return DP[idx][oxi][nit] = min(cyl[idx].second, dp(idx+1, oxi, nit));
	return DP[idx][oxi][nit] = min(dp(idx+1, oxi2, nit2)+cyl[idx].second, dp(idx+1, oxi, nit));
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d %d", &t, &a);
		scanf("%d", &n);
		for (i=0; i<n; i++)
			scanf("%d %d %d", &cyl[i].first.first, &cyl[i].first.second, &cyl[i].second);
		memset(DP, -1, sizeof DP);
		printf("%d\n", dp(0, t+22, a+80));
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

