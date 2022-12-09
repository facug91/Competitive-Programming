/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1016
        Name: Brush (II)
        Number: 1016
        Date: 19/08/2014
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



int n, w, x, point[50005], ans, act;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	scanf("%d", &TC);
	for (int it=1; it<=TC; it++) {
		scanf("%d %d", &n, &w);
		for (i=0; i<n; i++)
			scanf("%d %d", &x, &point[i]);
		sort(point, point+n);
		i = 0; ans = 0;
		while (i < n) {
			ans++;
			act = point[i++] + w;
			while ((i < n) && (point[i] <= act)) i++;
		}
		printf("Case %d: %d\n", it, ans);
	}
	
	return 0;
}
