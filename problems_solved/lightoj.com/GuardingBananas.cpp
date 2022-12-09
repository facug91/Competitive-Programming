/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1203
        Name: Guarding Bananas
        Number: 1203
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

struct point {
	double x, y;
	point() {x = y = 0.0;}
	point(double _x, double _y) : x(_x), y(_y) {};
	bool operator==(point p) {
		return (fabs(x-p.x) < EPS && fabs(y-p.y) < EPS);}
};
struct point_cmp {
	bool operator()(point a, point b) {
		if (a == b) return false;
		if (fabs(a.x-b.x) > EPS)
			return a.x - b.x > -EPS;
		return a.y - b.y > -EPS;
	}
};

point to_vec (point a, point b) {
	return point(b.x-a.x, b.y-a.y);}
double dist (point a, point b) {
	return hypot((b.x-a.x), (b.y-a.y));}
double cross (point a, point b) {
	return a.x*b.y - a.y*b.x;}
bool collinear (point p, point q, point r) {
	return fabs(cross(to_vec(p, q), to_vec(p, r))) < EPS;}
bool ccw (point p, point q, point r) {
	return cross(to_vec(p, q),to_vec(p, r)) > 0.0;}
double dot (point a, point b) {
	return a.x*b.x + a.y*b.y;}
double norm_sq (point v) {
	return v.x*v.x + v.y*v.y;}
double calc_angle (point a, point o, point b) {
	point oa = to_vec(o, a), ob = to_vec(o, b);
	return acos(dot(oa, ob) / (sqrt(norm_sq(oa)) * sqrt(norm_sq(ob))));
}

point pivot(0.0, 0.0);
bool angle_cmp(point a, point b) {
	if (a == b) return false;
	if (collinear(pivot, a, b))
		return dist(pivot, a) < dist(pivot, b);
	double d1x = a.x-pivot.x, d1y = a.y-pivot.y;
	double d2x = b.x-pivot.x, d2y = b.y-pivot.y;
	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < EPS;
}

vector<point> convex_hull (vector<point> &pol) {
	int i, j, n = (int)pol.size();
	if (n <= 3) {
		if (!(pol[0] == pol[n-1])) pol.push_back(pol[0]);
		return pol;
	}
	int p0 = 0;
	for (i=1; i<n; i++)
		if ((pol[i].y - pol[p0].y < EPS) || (fabs(pol[i].y - pol[p0].y) < EPS && (pol[i].x - pol[p0].x > -EPS))) p0 = i;
	point tmp = pol[0]; pol[0] = pol[p0]; pol[p0] = tmp;
	pivot = pol[0];
	sort(++pol.begin(), pol.end(), angle_cmp);
	vector<point> ans;
	ans.push_back(pol[n-1]);
	ans.push_back(pol[0]);
	ans.push_back(pol[1]);
	i = 2;
	int perro;
	while (i < n) {
		j = (int)ans.size()-1;
		if (ccw(ans[j-1], ans[j], pol[i])) ans.push_back(pol[i++]);
		else ans.pop_back();
	}
	return ans;
	
}

bool all_collinear (vector<point> pol) {
	for (int i=2; i<(int)pol.size(); i++) {
		if (!collinear(pol[i-2], pol[i-1], pol[i])) return false;
	}
	return true;
}

int n;
double x, y;
set<point, point_cmp> pol;
vector<point> convex_pol;

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	scanf("%d", &TC);
	for (int it=1; it<=TC; it++) {
		scanf("%d", &n);
		if (n <= 2) {
			scanf("%lf %lf", &x, &y);
			if (n == 2) scanf("%lf %lf", &x, &y);
			printf("Case %d: 0\n", it);
		} else {
			pol.clear();
			for (i=0; i<n; i++) {
				scanf("%lf %lf", &x, &y);
				pol.insert(point(x, y));
			}
			if (pol.size() <= 2) {
				printf("Case %d: 0\n", it);
			} else {
				vector<point> aux_v;
				for (set<point>::iterator itr=pol.begin(); itr!=pol.end(); itr++)
					aux_v.push_back(*itr);
				if (all_collinear(aux_v)) {
					printf("Case %d: 0\n", it);
				} else {
					convex_pol = convex_hull(aux_v);
					convex_pol.pop_back();
					double angle = MAX_DBL, aux; int size = (int)convex_pol.size();
					for (i=0; i<size; i++) {
						aux = calc_angle(convex_pol[((i-1)+size)%size], convex_pol[i], convex_pol[(i+1)%size]);
						if (angle-aux > -EPS) angle = aux;
					}
					printf("Case %d: %.9lf\n", it, angle*360.0/(2.0*PI));
				}
			}
		}
	}
	
	return 0;
}
