/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1944
        Name: Boxes
        Number: 11003
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

int n, box[1005][2], DP[1005][3005];

int dp (int idx, int w) {
	if (idx == n || w == 0) return 0;
	if (DP[idx][w] != -1) return DP[idx][w];
	if (box[idx][0] > w) return DP[idx][w] = dp(idx+1, w);
	return DP[idx][w] = max(dp(idx+1, w), dp(idx+1, min(w-box[idx][0], box[idx][1]))+1);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>n, n) {
		for (i=0; i<n; i++)
			cin>>box[i][0]>>box[i][1];
		memset(DP, -1, sizeof DP);
		int ans = -1;
		for (i=0; i<n-1; i++)
			ans = max(ans, dp(i+1, box[i][1]));
		cout<<ans+1<<endl;
	}
	
	return 0;
}

