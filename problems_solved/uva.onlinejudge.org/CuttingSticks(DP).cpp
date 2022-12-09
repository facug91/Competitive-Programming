/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=944
        Name: Cutting Sticks
        Number: 10003
        Date: 22/08/2014
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

int len, n, cut[55], DP[1005][1005];

int dp (int l, int r) {
	if (DP[l][r] != -1) return DP[l][r];
	int ans = MAX_INT, idx;
	for (idx=0; (idx<n) && (cut[idx]<=l); idx++);
	for (; (idx<n) && (cut[idx]<r); idx++)
		ans = min(ans, dp(l, cut[idx]) + dp(cut[idx], r) + r-l);
	if (ans == MAX_INT) return DP[l][r] = 0;
	cout<<"l "<<l<<" r "<<r<<" "<<ans<<endl;
	return DP[l][r] = ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	int i, j;
	
	while (cin>>len, len) {
		cin>>n;
		for (i=0; i<n; i++)
			cin>>cut[i];
		memset(DP, -1, sizeof DP);
		cout<<"The minimum cutting is "<<dp(0, len)<<".\n";
	}
	
	return 0;
}
