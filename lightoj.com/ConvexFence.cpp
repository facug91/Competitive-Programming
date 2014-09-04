/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1239
        Name: Convex Fence
        Number: 1239
        Date: 20/08/2014
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

struct point_i {
	ll x, y;
	point_i() {x = y = 0;}
	point_i(ll _x, ll _y) : x(_x), y(_y) {};
	bool operator==(point_i other) {
		return x == other.x && y == other.y; }
};

struct cmp {
	bool operator()(const point_i &a, const point_i &b) {
		if (a.x == b.x) return a.y < b.y;
		return a.x < b.x; }
}myCmp;

point_i to_vec (point_i &a, point_i &b) {
	return point_i(b.x-a.x, b.y-a.y); }
point_i perpendicular_left (point_i v) {
	return point_i(-v.y, v.x); }
point_i perpendicular_right (point_i v) {
	return point_i(v.y, -v.x); }
double dist (point_i &a, point_i &b) {
	return hypot(double (a.x-b.x), double (a.y-b.y)); }
ll cross (point_i &o, point_i &a, point_i &b) {
	return (a.x-o.x) * (b.y-o.y) - (a.y-o.y) * (b.x-o.x); }
double dot (point_i &a, point_i &b) {
	return (double)(a.x*b.x + a.y*b.y); }
double norm_sq (point_i &v) {
	return (double)(v.x*v.x + v.y*v.y); }
double angle (point_i oa, point_i ob) {
	return acos(dot(oa, ob) / (sqrt(norm_sq(oa)) * sqrt(norm_sq(ob)))); }
vector<point_i> convex_hull (vector<point_i> &pol) {
	int i, t, n = (int)pol.size(), k = 0;
	if (n <= 3) return pol;
	vector<point_i> ans(2*n);
	sort(pol.begin(), pol.end(), myCmp);
	for (i=0; i<n; i++) {
		while (k >= 2 && cross(ans[k-2], ans[k-1], pol[i]) <= 0) k--;
		ans[k++] = pol[i];
	}
	for (i=n-2, t=k+1; i>=0; i--) {
		while (k >= t && cross(ans[k-2], ans[k-1], pol[i]) <= 0) k--;
		ans[k++] = pol[i];
	}
	if (ans[0] == ans[k-1]) k--;
	ans.resize(k);
	return ans;
}

int n, size;
ll x, y;
vector<point_i> forest;
double d, ans, perimeter;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	scanf("%d", &TC);
	for (int it=1; it<=TC; it++) {
		forest.clear();
		scanf("%d %lf", &n, &d);
		for (i=0; i<n; i++) {
			scanf("%lld %lld", &x, &y);
			forest.push_back(point_i(x, y));
		}
		vector<point_i> convex = convex_hull(forest);
		size = (int)convex.size();
		perimeter = 2.0*PI*d;
		if (size == 1) {
			ans = perimeter;
		} else if (size == 2) {
			ans = perimeter + dist(convex[0], convex[1]) * 2.0;
		} else {
			ans = 0.0;
			for (i=0; i<size; i++) {
				ans += dist(convex[i], convex[(i+1)%size]);
				ans += (perimeter * angle(perpendicular_right(to_vec(convex[i], convex[(i+1)%size])), perpendicular_left(to_vec(convex[i], convex[(i-1+size)%size]))) / (2.0*PI));
			}
		}
		printf("Case %d: %.10lf\n", it, ans);
	}
	
	return 0;
}
