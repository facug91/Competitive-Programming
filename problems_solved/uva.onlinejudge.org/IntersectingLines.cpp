/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=314
        Name: Intersecting Lines
        Date: 11/11/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

struct point_i {
	int x, y;
	point_i () {x = y = 0;}
	point_i (int _x, int _y) : x(_x), y(_y) {};
};
struct point {
	double x, y;
	point () {x = y = 0.0;}
	point (double _x, double _y) : x(_x), y(_y) {};
};
struct line {
	double a, b, c;
	line () {a = b = c = 0.0;}
	line (double _a, double _b, double _c) : a(_a), b(_b), c(_c) {};
};

int n;
point_i p1, p2;
line l1, l2;

line points_to_line (point_i &p1, point_i &p2) {
	if (p1.x == p2.x) return line(1.0, 0.0, -(double)p1.x);
	line l;
	l.a = -(double)(p1.y - p2.y)/(double)(p1.x - p2.x);
	l.b = 1.0;
	l.c = -(l.a * (double)p1.x) - (double)p1.y;
	return l;
}
bool are_parallel (line &l1, line &l2) {
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}
bool are_same (line &l1, line &l2) {
	return are_parallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}
point intersection (line &l1, line &l2) {
	point p;
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
	else p.y = -(l2.a * p.x + l2.c);
	return p;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	scanf("%d", &n);
	printf("INTERSECTING LINES OUTPUT\n");
	while (n--) {
		scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);
		l1 = points_to_line(p1, p2);
		scanf("%d %d %d %d", &p1.x, &p1.y, &p2.x, &p2.y);
		l2 = points_to_line(p1, p2);
		if (are_same(l1, l2)) printf("LINE\n");
		else if (are_parallel(l1, l2)) printf("NONE\n");
		else {
			point ans = intersection(l1, l2);
			printf("POINT %.02lf %.02lf\n", ans.x, ans.y);
		}
	}
	printf("END OF OUTPUT\n");
	
	return 0;
}
