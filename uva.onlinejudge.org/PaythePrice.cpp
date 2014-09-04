/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1254
        Name: Pay the Price
        Number: 10313
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
//#define MAXN 6005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n[3], cant;
ll DP[305][305];
char in[20], *p;

void dp () {
	int i, j;
	for (i=0; i<305; i++)
		DP[0][i] = 1;
	for (i=1; i<305; i++) {
		for (j=1; j<=i; j++)
			DP[i][j] += DP[i-j][j] + DP[i][j-1];
		for (j=i+1; j<305; j++)
			DP[i][j] = DP[i][j-1];
	}
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	dp();
	
	while (gets(in)) {
		cant = 0;
		p = strtok(in, " ");
		while (p != NULL) {
			n[cant++] = atoi(p);
			p = strtok(NULL, " ");
		}
		if (cant == 1) printf("%lld\n", DP[n[0]][n[0]]);
		else if (cant == 2) {
			if (n[1] > n[0]) n[1] = n[0];
			printf("%lld\n", DP[n[0]][n[1]]);
		} else {
			if (n[1] > n[0]) printf("0\n");
			else {
				if (n[2] > n[0]) n[2] = n[0];
				if (n[1] == 0) printf("%lld\n", DP[n[0]][n[2]]);
				else printf("%lld\n", DP[n[0]][n[2]] - DP[n[0]][n[1]-1]);
			}
		}
	}
	
	return 0;
}

