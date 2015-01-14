/*
        By: facug91
        From: http://www.spoj.com/problems/OHANISER/
        Name: Ohani And The Series
        Date: 14/11/2014
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

int n;
ll DP[100005];

void dp () {
	int i;
	ll k = 1ll;
	DP[1] = 1;
	for (i=2; i<100005; i++) {
		DP[i] = (DP[i-1]*2ll+k) % MOD;
		k = (k * 2ll) % MOD;
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	dp();
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>n;
		cout<<"Case "<<it<<": "<<DP[n]<<endl;
	}
	
	return 0;
}
