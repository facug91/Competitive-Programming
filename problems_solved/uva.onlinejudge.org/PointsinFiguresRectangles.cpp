/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=417
        Name: Points in Figures: Rectangles
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

struct point {
	double x, y;
	point () {x = y = 0.0;}
	point(double _x, double _y) : x(_x), y(_y) {};
};

int n, np;
char op;
point upper_left, lower_right, p;
point rectangles[15][5];

point to_vec (const point &a, const point &b) {
	return point(a.x-b.x, a.y-b.y);
}
double cross (point a, point b) {
	return ((a.x*b.y) - (a.y*b.x));
}
bool ccw (point p, point q, point r) {
	return cross(to_vec(p, q), to_vec(p, r)) > 0.0;
}
bool is_inside (int idx) {
	int i;
	for (i=0; i<4; i++) {
		if (!ccw(rectangles[idx][i], rectangles[idx][i+1], p)) {
			return false;
		}
	}
	return true;
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	int n = 1;
	while (scanf(" %c", &op), op != '*') {
		scanf("%lf %lf", &upper_left.x, &upper_left.y);
		scanf("%lf %lf", &lower_right.x, &lower_right.y);
		
		rectangles[n][0].x = upper_left.x;
		rectangles[n][0].y = upper_left.y;
		
		rectangles[n][1].x = upper_left.x;
		rectangles[n][1].y = lower_right.y;
		
		rectangles[n][2].x = lower_right.x;
		rectangles[n][2].y = lower_right.y;
		
		rectangles[n][3].x = lower_right.x;
		rectangles[n][3].y = upper_left.y;
		
		rectangles[n][4].x = upper_left.x;
		rectangles[n][4].y = upper_left.y;
		
		n++;
	}
	
	np = 1;
	while (scanf("%lf %lf", &p.x, &p.y), !((fabs(p.x - 9999.9) < EPS) && (fabs(p.y - 9999.9) < EPS))) {
		bool any = false;
		for (i=1; i<=n; i++) {
			if (is_inside(i)) {
				printf("Point %d is contained in figure %d\n", np, i);
				any = true;
			}
		}
		if (!any) {
			printf("Point %d is not contained in any figure\n", np);
		}
		np++;
	}
	
	return 0;
}
