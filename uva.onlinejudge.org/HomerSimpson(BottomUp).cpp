/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1406
        Name: Homer Simpson
        Number: 10465
        Date: 09/09/2014
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

int m, n, t, DP[10005];
ii ans;

void dp () {
	int i;
	DP[0] = 0;
	for (i=1; i<=t; i++)
		DP[i] = -1;
	for (i=0; i<=t; i++) {
		if (i>=n && DP[i-n]!=-1) DP[i] = DP[i-n]+1;
		if (i>=m && DP[i-m]!=-1) DP[i] = max(DP[i], DP[i-m]+1); 
	}
	for (i=t; (i>=0)&&(DP[i]==-1); i--);
	if (i == -1) {
		ans.first = 0;
		ans.second = t;
	} else {
		ans.first = DP[i];
		ans.second = t-i;
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>m>>n>>t) {
		dp();
		cout<<ans.first;
		if (ans.second) cout<<" "<<ans.second;
		cout<<endl;
	}
	
	return 0;
}

