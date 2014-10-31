/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1114
        Name: Smallest Bounding Rectangle
        Date: 31/10/2014
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
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

struct point {
	double x, y;
	point () {x = y = 0.0;}
	point (double _x, double _y) : x(_x), y(_y) {};
	bool operator==(point other) const {
		return fabs(x-other.x) < EPS && fabs(y-other.y) < EPS;
	}
	bool operator!=(point other) const {
		return !((*this)==other);
	}
	bool operator<(point other) const {
		if (fabs(x-other.x) < EPS) return y - other.y < -EPS;
		return x - other.x < -EPS;
	}
};

int n;
double x, y;
vector<point> P, CH;

point to_vec (const point &a, const point &b) {
	return point(b.x-a.x, b.y-a.y);
}
double cross (const point &v1, const point &v2) {
	return v1.x * v2.y - v1.y * v2.x;
}
bool collinear (const point &p, const point &q, const point &r) {
	return fabs(cross(to_vec(p, q), to_vec(p, r))) < EPS;
} 
bool ccw (const point &p, const point &q, const point &r) {
	return cross(to_vec(p, q), to_vec(p, r)) > EPS;
}
double dot (const point &v1, const point &v2) {
	return v1.x * v2.x + v1.y * v2.y;
}
double norm_sq (const point &v) {
	return v.x * v.x + v.y * v.y;
}
point scale (const point &v, double s) {
	return point(v.x*s, v.y*s);
}
point translate (const point &a, const point &v) {
	return point(a.x+v.x, a.y+v.y);
}
double dist_point (const point &a, const point &b) {
	return hypot(a.x-b.x, a.y-b.y);
}
bool in_segment (const point &a, const point &b, const point &c) {
	return (c.x >= min(a.x, b.x)) && (c.y >= min(a.y, b.y)) && (max(a.x, b.x) >= c.x) && (max(a.y, b.y) >= c.y);
}
point closest_point (const point &p, const point &a, const point &b) {
	point ap = to_vec(a, p), ab = to_vec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	return translate(a, scale(ab, u));
}

point pivot;
bool angle_cmp (const point &a, const point &b) {
	if (collinear(pivot, a, b))
		return dist_point(pivot, a) < dist_point(pivot, b);
	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	return atan2(d1y, d1x) - atan2(d2y, d2x) < 0.0;
}

vector<point> convex_hull (vector<point> &P) {
	int i, j, n = (int)P.size();
	
	if (n <= 2) {
		if (P[0] != P[n-1]) P.push_back(P[0]);
		return P;
	}
	
	int P0 = 0;
	for (i=1; i<n; i++)
		if ((P[P0].y > P[i].y) || (P[P0].y == P[i].y && P[P0].x < P[i].x))
			P0 = i;
	
	pivot = P[P0];
	point tmp = P[0]; P[0] = P[P0]; P[P0] = tmp;
	sort(++P.begin(), P.end(), angle_cmp);
	
	vector<point> S;
	S.push_back(P[n-1]); S.push_back(P[0]); S.push_back(P[1]);
	i = 2;
	while (i < n) {
		j = (int)S.size() - 1;
		if (j == 1) S.push_back(P[i++]);
		else if (ccw(S[j-1], S[j], P[i])) S.push_back(P[i++]);
		else S.pop_back();
	}
	
	return S;
}

double solve (vector<point> &P) {
	int i, j;
	double h, w;
	bool first = true;
	for (i=1; i<(int)P.size(); i++) {
		point bottom((P[i-1].x+P[i].x)/2.0, (P[i-1].y+P[i].y)/2.0);
		point left(P[i-1].x, P[i-1].y);
		point right(P[i].x, P[i].y);
		double left_d = dist_point(bottom, left);
		double right_d = dist_point(bottom, right);
		double top_d = 0.0;
		double d;
		for (j=0; j<(int)P.size(); j++) {
			point close = closest_point(P[j], P[i-1], P[i]);
			d = dist_point(P[j], close);
			if (d > top_d)
				top_d = d;
			if (!in_segment(left, right, close)) {
				d = dist_point(bottom, close);
				if (d > dist_point(left, close)) {
					if (d > left_d) {
						left_d = d;
						left = close;
					}
				} else {
					if (d > right_d) {
						right_d = d;
						right = close;
					}
				}
			}
		}
		if (first) {
			first = false;
			h = top_d;
			w = right_d + left_d;
		} else {
			if ((h * w) > (top_d * (right_d + left_d))) {
				h = top_d;
				w = right_d + left_d;
			}
		}
	}
	return h * w;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>n, n) {
		P.clear();
		for (i=0; i<n; i++) {
			cin>>x>>y;
			P.push_back(point(x, y));
		}
		CH = convex_hull(P);
		
		if ((int)CH.size() <= 3) printf("0.0000\n");
		else printf("%.04lf\n", solve(CH));
	}
	
	return 0;
}
