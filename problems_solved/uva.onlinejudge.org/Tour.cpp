/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4093
        Name: Tour
        Number: 1347
        Date: 12/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 131071
//#define MAXN 10000010

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

struct point {
	int x, y;
	point() {x = y = 0;}
	point(int _x, int _y) : x(_x), y(_y) {};
};
double dist_point (const point &a, const point &b) {
	return hypot((double) (a.x - b.x), (double) (a.y - b.y));
}
 
int n, x, y;
vector<point> points;
double DP[1005][1005];
 
double dp (int p1, int p2) {
	int next = max(p1, p2) + 1;
	if (DP[p1][p2] != -0.5) return DP[p1][p2];
	if (next == n-1) return DP[p1][p2] = dist_point(points[p1], points[n-1]) + dist_point(points[p2], points[n-1]);
	return DP[p1][p2] = min(dp(next, p2)+dist_point(points[p1], points[next]), dp(p1, next)+dist_point(points[p2], points[next]));
}
 
int main() {
	int i, j;
 
	while (cin>>n) {
		for (i=0; i<n; i++) {
			cin>>x>>y;
			points.push_back(point(x, y));
		}
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++) {
				DP[i][j] = -0.5;
			}
		}
		printf("%.2lf\n", dp(0, 0));
		points.clear();
	}
 
	return 0;
}
