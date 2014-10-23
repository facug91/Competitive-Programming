/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=953
        Name: How Big Is It?
        Date: 18/10/2014
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

int n;
double radius[10], ans;

void solve () {
	if (n == 0) {
		ans = 0.0;
		return;
	}
	int i, j;
	double place[10], width;
	sort(radius, radius+n);
	ans = MAX_DBL;
	do {
		place[0] = radius[0];
		width = radius[0]*2;
		for (i=1; i<n; i++) {
			place[i] = radius[i];
			for (j=0; j<i; j++) {
				place[i] = max(place[i], place[j]+((fabs(radius[i]-radius[j]) < EPS) ? (radius[i]+radius[j]) : sqrt(((radius[i]+radius[j])*(radius[i]+radius[j]))-(fabs(radius[i]-radius[j])*fabs(radius[i]-radius[j])))));
			}
			if (place[i]+radius[i] > width) width = place[i]+radius[i];
		}
		if (width < ans) ans = width;
	} while (next_permutation(radius, radius+n));
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d", &n);
		for (i=0; i<n; i++) {
			scanf("%lf", &radius[i]);
		}
		solve();
		printf("%.03lf\n", ans);
	}
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
