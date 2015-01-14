/*
        By: facug91
        From: http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemId=90
        Name: The Circumference of the Circle
        Date: 11/11/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
//const double PI = 2.0*acos(0.0);
const double PI = 3.141592653589793;

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

struct point {
	double x, y;
	point () {x = y = 0.0;}
	point (double _x, double _y) : x(_x), y(_y) {};
};

point t[3];

double dist_point (point &a, point &b) {
	return hypot(b.x-a.x, b.y-a.y);
}
double r_circum_circle () {
	double a = t[1].x - t[0].x, b = t[1].y - t[0].y;
	double c = t[2].x - t[0].x, d = t[2].y - t[0].y;
	double e = a * (t[0].x + t[1].x) + b * (t[0].y + t[1].y);
	double f = c * (t[0].x + t[2].x) + d * (t[0].y + t[2].y);
	double g = 2.0 * (a * (t[2].y - t[1].y) - b * (t[2].x - t[1].x));
	point ctr = point((d*e - b*f) / g, (a*f - c*e) / g);
	return dist_point(t[0], ctr);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (scanf("%lf %lf %lf %lf %lf %lf", &t[0].x, &t[0].y, &t[1].x, &t[1].y, &t[2].x, &t[2].y) != EOF)
		printf("%.02lf\n", 2.0 * PI * r_circum_circle());
	
	return 0;
}
