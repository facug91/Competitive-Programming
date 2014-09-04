/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1047
        Name: Neighbor House
        Number: 1047
        Date: 28/08/2014
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
//#define MAXN 6005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, DP[21][4], house[21][4];

int dp (int idx, int color) {
	if (idx == n) return 0;
	if (DP[idx][color] != -1) return DP[idx][color];
	return DP[idx][color] = min(dp(idx+1, (color+1)%3), dp(idx+1, (color+2)%3)) + house[idx][color];
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>n;
		for (i=0; i<n; i++)
			cin>>house[i][0]>>house[i][1]>>house[i][2];
		memset(DP, -1, sizeof DP);
		cout<<"Case "<<it<<": "<<min(min(dp(0, 0), dp(0, 1)), dp(0, 2))<<endl;
	}
	
	return 0;
}

