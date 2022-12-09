/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2970
	Name: Humbertov’s Flag
	Number: 2970
	Date: 12/07/2014
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
#define _log2(x) log(x) * 1.44269504088896340736
//const long double PI = 2*acos(0);

#define INF 1000000000

using namespace std;

struct point {
	double x, y;
	point(double _x, double _y) : x(_x), y(_y) {}
	bool operator == (point other) const {
		return (fabs(x - other.x) < EPS && (fabs(y-other.y) < EPS));
	}
};

struct vec {
	double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec to_vec (point a, point b) {
	return vec(b.x-a.x, b.y-a.y);
}

double dist (point p1, point p2) {
	return hypot(p1.x-p2.x, p1.y-p2.y);
}

double cross (vec a, vec b) {
	return a.x * b.y - a.y * b.x;
}

bool collinear (point p1, point p2, point p3) {
	return fabs(cross(to_vec(p1, p2), to_vec(p1, p3))) < EPS;
}

point pivot(0.0, 0.0);
bool angleCmp (point a, point b) {
	if (collinear(pivot, a, b))
		return dist(pivot, a) < dist(pivot, b);
	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

vector<point> make_polygon (vector<point> P) {
	int i, j, n = P.size();
	if (n <= 3) {
		if (!(P[0] == P[n-1])) P.push_back(P[0]);
		return P;
	}
	
	int P0 = 0;
	for (i=1; i<n; i++) {
		if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
			P0 = i;
	}
	
	point temp = P[0];
	P[0] = P[P0];
	P[P0] = temp;
	
	pivot = P[0];
	sort(++P.begin(), P.end(), angleCmp);
	
	return P;
	
}

int n;
vector<point> P;

int main () {
	int i, j, x, y;
	
	while (scanf("%d", &n) != EOF) {
		
		P.clear();
		for (i=0; i<n; i++) {
			scanf("%d %d", &x, &y);
			P.push_back(point((double) x, (double) y));
		}
		
		P = make_polygon(P);
		
		printf("%d\n", n);
		for (i=0; i<n; i++)
			printf("%d %d\n", (int)P[i].x, (int)P[i].y);
		
	} 
	
	return 0;
}
