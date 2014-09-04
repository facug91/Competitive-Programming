/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1007
        Name: The Twin Towers
        Number: 10066
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

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int n1, n2, seq1[105], seq2[105], LCS[105][105];

int lcs () {
	int i, j;
	for (i=0; i<=n1; i++) LCS[i][0] = 0;
	for (j=0; j<=n2; j++) LCS[0][j] = 0;
	for (i=1; i<=n1; i++) {
		for (j=1; j<=n2; j++) {
			if (seq1[i] == seq2[j]) LCS[i][j] = LCS[i-1][j-1] + 1;
			else LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
		}
	}
	return LCS[n1][n2];
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC = 1, i, j;
	
	while (scanf("%d %d", &n1, &n2), n1 || n2) {
		for (i=1; i<=n1; i++)
			scanf("%d", &seq1[i]);
		for (j=1; j<=n2; j++)
			scanf("%d", &seq2[j]);
		printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", TC++, lcs());
	}
	
	return 0;
}
