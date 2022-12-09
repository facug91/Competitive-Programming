/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2958
        Name: Almost Complete Binary Tree
        Number: 2958
        Date: 15/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007
//#define MAXN 3000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, DP[1000][2100];

void dp () {
	int i, j;
	for (i=0; i<1000; i++)
		DP[i][i] = 1;
	for (j=0; j<2100; j++)
		DP[1][j] = j;
	for (i=2; i<1000; i++)
		for (j=2; j<2100; j++)
			DP[i][j] = (DP[i][j-1] + DP[i-1][j-1]) % MOD;
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	dp();
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d", &n);
		for (i=0; n>((1<<i)-1); i++);
		printf("%d\n", (DP[n-((1<<(i-1))-1)][1<<(i-1)]+MOD-1)%MOD);
	}
	
	return 0;
}
