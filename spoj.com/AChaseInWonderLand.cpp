/*
        By: facug91
        From: http://www.spoj.com/problems/CHASE/
        Name: A Chase In WonderLand
        Date: 26/10/2015
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
//#define MAXN 3000
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 
struct point {
	int x, y;
	point () {x = y = 0;}
	point(int _x, int _y) : x(_x), y(_y) {};
};
 
int n, m;
point points[2300];
double slopes[2300];
 
int solve () {
	int i, j, ans = 1, a, b, aux;
	for (i=0; i<n-1; i++) {
		m = 0;
		for (j=i+1; j<n; j++) {
			if (points[i].x == points[j].x) slopes[m++] = INF+0.0;
			else slopes[m++] = (double)(points[i].y-points[j].y)/(double)(points[i].x-points[j].x);
		}
		sort(slopes, slopes+m);
		aux = 1;
		for (j=1; j<m; j++) {
			if (fabs(slopes[j] - slopes[j-1]) < EPS) aux++;
			else {
				ans = max(ans, aux);
				aux = 1;
			}
		}
		ans = max(ans, aux);
	}
	return ans+1;
}
 
int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d", &n);
		for (i=0; i<n; i++) scanf("%d %d", &points[i].x, &points[i].y);
		if (n < 2) printf("0\n");
		else printf("%d\n", solve()-1);
	}
	
	return 0;
}
