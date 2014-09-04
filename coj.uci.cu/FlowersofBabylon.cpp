/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2556
	Name: Flowers of Babylon
	Number: 2556
	Date: 13/08/2014
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
//#define MOD 1000000007
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
 
struct point {
	double x, y;
	point() {x = y = 0.0;}
	point(double _x, double _y) : x(_x), y(_y) {};
};
 
int n, p;
double x, y;
vector<point> flower;
vector<pair<point, int> > center;
set<int> inside;
 
double dist (point a, point b) {return hypot(a.x-b.x, a.y-b.y);}
bool inside_circle (point p, point c, double r) {
	double dx = p.x - c.x, dy = p.y - c.y;
	double euc = dx * dx + dy * dy, rSq = r*r;
	return euc <= rSq;
}
point to_vec (point a, point b) {return point(b.x-a.x, b.y-a.y);}
point scale (point a, double s) {return point(a.x*s, a.y*s);}
point translate (point a, point b) {return point(a.x+b.x, a.y+b.y);}
point perpendicular_left (point a) {return point(-a.y, a.x);}
point perpendicular_right (point a) {return point(a.y, -a.x);}
double norm_sq (point v) {return v.x*v.x + v.y*v.y;}
double cross (point a, point b) {return a.x*b.y - a.y*b.x;}
 
point pivot;
bool angle_cmp (const pair<point, int> &a, const pair<point, int> &b) {
	if (a.first.x - pivot.x >= -EPS && b.first.x - pivot.x  < EPS) return true;
	if (a.first.x - pivot.x  < EPS && b.first.x - pivot.x >= -EPS) return false;
	if (a.first.x - pivot.x < EPS && a.first.x - pivot.x > -EPS && b.first.x - pivot.x < EPS && b.first.x - pivot.x > -EPS) {
		if (a.first.y - pivot.y >= -EPS || b.first.y - pivot.y >= -EPS) return a.first.y > b.first.y;
		return b.first.y > a.first.y;
	}
	double det = cross(to_vec(pivot, a.first), to_vec(pivot, b.first));
	if (det < EPS) return true;
	if (det > -EPS) return false;
	return a.second < b.second;
}
 
bool check_radio (double r) {
	int i, j;
	double d = r*2.0, dis, h2, s;
	point mid, vec1, vec2;
	for (i=0; i<n; i++) {
		center.clear();
		for (j=0; j<n; j++) {
			if (j != i) {
				dis = dist(flower[i], flower[j]);
				if (d - dis > -EPS) {
					mid = point((flower[i].x+flower[j].x)/2.0, (flower[i].y+flower[j].y)/2.0);
					vec1 = to_vec(flower[i], flower[j]);
					h2 = ((r*r)-(dis*dis/4.0));
					s = sqrt(h2/norm_sq(vec1));
					vec2 = scale(perpendicular_left(vec1), s);
					center.push_back(make_pair(translate(vec2, mid), j*2));
					vec2 = scale(perpendicular_right(vec1), s);
					center.push_back(make_pair(translate(vec2, mid), j*2+1));
				}
			}
		}
		if (center.size() != 0) {
			pivot = flower[i];
			sort(center.begin(), center.end(), angle_cmp);
			//sweep circle
			pair<point, int> act = center[0];
			inside.clear();
			for (j=0; j<n; j++)
				if ((j != i) && (inside_circle(flower[j], act.first, r)))
					inside.insert(j);
			for (j=0; j<(int)center.size(); j++) {
				act = center[j];
				if (act.second % 2 == 0) {
					inside.insert(act.second/2);
					if ((int)inside.size() == p-1) return true;
				} else {
					inside.erase(act.second/2);
				}
			}
		}
	}
	return false;
}
 
double binary_search () {
	double lo = 0.0, hi = 75000.0, mid;
	while (fabs(hi-lo) > 0.000001) {
		mid = (hi+lo)/2.0;
		if (check_radio(mid)) hi = mid;
		else lo = mid;
	}
	return (hi+lo)/2.0;
}
 
int main () {
	int t, i, j;
	
	scanf("%d %d", &n, &p);
	if (p == 1)	printf("0.0000\n");
	else {
		for (i=0; i<n; i++) {
			scanf("%lf %lf", &x, &y);
			flower.push_back(point(x, y));
		}
		printf("%.4lf\n", binary_search());
	}
	
	return 0;
}
