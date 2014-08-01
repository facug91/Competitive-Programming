/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1433
	Name: Minimum Arc Distance
	Number: 1433
	Date: 25/07/2014
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iterator>
#include <utility>
#include <list>
#include <stack>
#include <iomanip>
#include <bitset>

#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

struct point {
	double x, y;
	point() {x = y = 0;}
	point(double _x, double _y) : x(_x), y(_y) {}
};

point p[3];
double r, c, alfa, arc;

double dist (point p1, point p2) {return hypot(p1.x - p2.x, p1.y - p2.y);}
point toVector (point a, point b) {return point(b.x-a.x, b.y-a.y);}
double dot (point a, point b) {return (a.x * b.x + a.y * b.y);}
double norm_sq (point v) {return (v.x * v.x + v.y * v.y);}
double angle (point a, point o, point b) {
	point oa = toVector(o, a), ob = toVector(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

int main () {
	int t, i, j;
	
	scanf("%d", &t);
	for (int it=1; it<=t; it++) {
		for (i=0; i<3; i++)
			scanf("%lf %lf", &p[i].x, &p[i].y);
		r = dist(p[0], p[1]);
		c = 2.0*PI*r;
		alfa = angle(p[1], p[0], p[2]);
		arc = c*alfa/(2.0*PI);
		printf("Case %d: %.9lf\n", it, arc);
	}
	
	return 0;
}
