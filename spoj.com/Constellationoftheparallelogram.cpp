/*
        By: facug91
        From: http://www.spoj.com/problems/TAP2014C/
        Name: Constellation of the parallelogram
        Number: 21170
        Date: 07/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 131071
//#define MAXN 10000010

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

struct Point {
	int x, y;
	Point() {x = y = 0;}
	Point(int _x, int _y) : x(_x), y(_y) {};
};

struct Segment {
	Point p1, p2;
	double m, l;
	Segment (const Point &_p1, const Point &_p2) {
		p1.x = _p1.x;
		p1.y = _p1.y;
		p2.x = _p2.x;
		p2.y = _p2.y;
		m = (p1.x == p2.x) ? 1.0 : ((double)(p1.y-p2.y))/((double)(p1.x-p2.x));
		l = hypot((double)(p1.x-p2.x), (double)(p1.y-p2.y));
	}
};

struct cmp {
	bool operator() (const Segment &s1, const Segment &s2) {
		if (fabs(s1.m-s2.m) < EPS) return s1.l < s2.l;
		return s1.m < s2.m;
	}
};

Point to_vec (const Point &a, const Point &b) {
	return Point(a.x-b.x, a.y-b.y);
}
int cross (const Point &a, const Point &b) {
	return (a.x*b.y - a.y*b.x);
} 
bool collinear (const Point &p, const Point &q, const Point &r) {
	return (cross(to_vec(p, q), to_vec(p, r)) == 0);
}

int n, x, y, ans;
vector<Point> points;
vector<Segment> segments;

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j, k;
	
	scanf("%d", &n);
	for (i=0; i<n; i++) {
		scanf("%d %d", &x, &y);
		points.push_back(Point(x, y));
	}
	for (i=0; i<n; i++) {
		for (j=i+1; j<n; j++) {
			segments.push_back(Segment(points[i], points[j]));
		}
	}
	sort(segments.begin(), segments.end(), cmp());
	ans = 0;
	for (i=0; i<(int)segments.size(); i++) {
		j = i+1; k = 0;
		while ((j<(int)segments.size()) && (fabs(segments[i].m-segments[j].m) < EPS) && (fabs(segments[i].l-segments[j].l) < EPS)) {
			if (!collinear(segments[i].p1, segments[i].p2, segments[j].p1)) k++;
			j++;
		}
		i = j - 1;
		ans += (k * (k-1) / 2);
	}
	printf("%d\n", ans/2);
	
	return 0;
}
