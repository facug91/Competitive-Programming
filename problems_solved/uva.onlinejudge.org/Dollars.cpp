/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=83
        Name: Dollars
        Number: 147
        Date: 27/08/2014
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
#define MAXN 6005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

ll DP[MAXN];
int n, z, d, coin[] = {2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};

void dp () {
	int i, j;
	for (i=0; i<MAXN; i++)
		DP[i] = 1;
	for (j=0; j<10; j++)
		for (i=coin[j]; i<MAXN; i++)
			DP[i] += DP[i-coin[j]];
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	dp();
	while (scanf("%d.%d", &z, &d), z || d) {
		n = (z*100+d)/5;
		printf("%3d.%02d%17lld\n", z, d, DP[n]);
	}
	
	return 0;
}

