/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1760
        Name: Trouble of 13-Dots
        Number: 10819
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

int m, n, DP[105][10005];
ii item[105];

int dp (int idx, int w, int limit) {
	if (idx == n) return 0;
	if (DP[idx][w] != -1) return DP[idx][w];
	if ((w <= 2000) && (item[idx].first+w > 2000)) {
		if (item[idx].first+w > limit+200) return DP[idx][w] = dp(idx+1, w, limit);
		return DP[idx][w] = max(dp(idx+1, w, limit), dp(idx+1, w+item[idx].first, limit+200) + item[idx].second);
	}
	if (item[idx].first+w > limit) return DP[idx][w] = dp(idx+1, w, limit);
	return DP[idx][w] = max(dp(idx+1, w, limit), dp(idx+1, w+item[idx].first, limit)+item[idx].second); 
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>m>>n) {
		for (i=0; i<n; i++)
			cin>>item[i].first>>item[i].second;
		memset(DP, -1, sizeof DP);
		cout<<dp(0, 0, m)<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

