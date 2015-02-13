/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2427
        Name: How Many Primes?
        Date: 01/02/2015
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

int DP[1000005];

void dp () {
	int i, j;
	DP[2] = 1;
	for (i=3; i<1000005; i+=2) DP[i] = 1;
	for (i=3; i<1005; i++)
		if (DP[i])
			for (j=i*i; j<1000005; j+=i+i)
				DP[j] = 0;
	for (i=2; i<1000005; i++)
		DP[i] += DP[i-1];
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	int a, b;
	
	dp();
	while (cin>>a>>b, a || b) cout<<DP[b]-DP[a-1]<<endl;
	
	return 0;
}
