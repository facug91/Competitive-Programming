/*
        By: facug91
        From: http://www.spoj.com/problems/LARSUBP/
        Name: Large subsequence Problem
        Date: 15/11/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

ll DP[10];
string s;

ll dp () {
	ll ans = 0ll;
	int i, j, k;
	memset(DP, 0, sizeof DP);
	for (i=0; i<(int)s.size(); i++) {
		k = s[i] - '0';
		ans = (ans + DP[k] + 1ll) % MOD;
		for (j=k+1; j<10; j++) {
			DP[j] = (DP[j] + DP[k] + 1ll) % MOD;
		}
	}
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>s;
		cout<<"Case "<<it<<": "<<dp()<<endl;
	}
	
	return 0;
}
