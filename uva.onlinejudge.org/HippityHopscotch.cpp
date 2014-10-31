/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1200
        Name: Hippity Hopscotch
        Date: 28/10/2014
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
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, k, grid[105][105], DP[105][105], di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};

bool check_pos (int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}
int dp (int x, int y) {
	if (DP[x][y] != -1) return DP[x][y];
	int ans = 0;
	for (int i=1; i<=k; i++) {
		for (int d=0; d<4; d++) {
			int w = x + di[d]*i;
			int z = y + dj[d]*i;
			if (check_pos(w, z) && grid[x][y] < grid[w][z])
				ans = max(ans, dp(w, z));
		}
	}
	return DP[x][y] = ans + grid[x][y];
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n>>k;
		for (i=0; i<n; i++)
			for (j=0; j<n; j++)
				cin>>grid[i][j];
		memset(DP, -1, sizeof DP);
		cout<<dp(0, 0)<<endl;
		if (TC) cout<<endl;
	}
	
	return 0;
}
