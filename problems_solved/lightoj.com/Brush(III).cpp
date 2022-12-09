/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1017
        Name: Brush (III)
        Number: 1017
        Date: 19/08/2014
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

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int n, w, k, x, point[105], DP[105][105];

int dp (int idx, int k) {
	if ((idx == n) || (k == 0)) return 0;
	if (DP[idx][k] != -1) return DP[idx][k];
	int i;
	for (i=idx+1; (i<n) && (point[i]<=point[idx]+w); i++);
	return DP[idx][k] = max(i-idx+dp(i, k-1), dp(idx+1, k));
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>n>>w>>k;
		for (i=0; i<n; i++)
			cin>>x>>point[i];
		sort(point, point+n);
		memset(DP, -1, sizeof DP);
		cout<<"Case "<<it<<": "<<dp(0, k)<<"\n";
	}
	
	return 0;
}
