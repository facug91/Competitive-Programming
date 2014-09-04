/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?abb=2111
        Name: Milestones
        Number: 2111
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

int n, k, c, l, r, rsq[10001][256], ans;

int main () {
	ios_base::sync_with_stdio(0);
	int i, j;
	
	memset(rsq, 0, sizeof rsq);
	scanf("%d %d", &n, &k);
	for (i=1; i<=n; i++) {
		scanf("%d", &c);
		rsq[i][c] = 1;
	}
	for (i=1; i<=n; i++)
		for (j=1; j<=255; j++)
			rsq[i][j] += rsq[i-1][j];
	for (i=0; i<k; i++) {
		scanf("%d %d", &l, &r);
		ans = 0;
		for (j=1; j<=255; j++)
			ans += ((rsq[r][j] - rsq[l-1][j]) > 0);
		printf("%d\n", ans);
	}
	
	return 0;
}
