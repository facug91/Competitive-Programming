/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2434
        Name: Mathematician Ana
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

bool sieve[100];
ll DP[100];

void init () {
	int i, j;
	memset(sieve, -1, sizeof sieve);
	for (i=2; i<10; i++)
		if (sieve[i])
			for (j=i*i; j<100; j+=i)
				sieve[j] = false;
	DP[1] = 1;
	for (i=2; i<100; i++)
		DP[i] = DP[i-1] * ((sieve[i])?i:1);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j, n;
	
	init();
	while (cin>>n, n) cout<<DP[n]<<endl;
	
	return 0;
}
