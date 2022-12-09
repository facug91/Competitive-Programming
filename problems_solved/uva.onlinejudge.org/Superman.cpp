/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1296
        Name: Superman
        Date: 27/10/2014
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
	double x, y, z;
	point () {x = y = z = 0.0;}
	point (double _x, double _y, double _z) : x(_x), y(_y), z(_z) {};
	bool operator==(const point &other) {
		return (fabs(x-other.x) < EPS) && (fabs(y-other.y) < EPS) && (fabs(z-other.z) < EPS);
	}
	bool operator!=(const point &other) {
		return !((*this) == other);
	}
};
struct vec {
	double x, y, z;
	vec () {x = y = z = 0.0;}
	vec (double _x, double _y, double _z) : x(_x), y(_y), z(_z) {};
	vec (const point &a, const point &b) {
		x = b.x-a.x; y = b.y-a.y; z = b.z-a.z;
	}
};
struct sphere {
	point c;
	double r;
	sphere () {c = point(); r = 0.0;}
	sphere (const point &p, double _r) {
		c.x = p.x; c.y = p.y; c.z = p.z;
		r = _r;
	}
};

int n, r;
string city;
point start, end, p;
vector<sphere> spheres;

double dist_point (const point &a, const point &b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + (a.z-b.z)*(a.z-b.z));
}
double dot (const vec &a, const vec &b) {
	return (a.x*b.x + a.y*b.y + a.z*b.z);
}
double norm_sq (const vec &v) {
	return (v.x*v.x + v.y*v.y + v.z*v.z);
}
vec scale (const vec &v, double s) {
	return vec(v.x*s, v.y*s, v.z*s);
}
point translate (const point &a, const vec &v) {
	return point(a.x+v.x, a.y+v.y, a.z+v.z);
}
point closest_point (const point &p, const point &a, const point &b) {
	vec ap = vec(a, p), ab = vec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	return translate(a, scale(ab, u));
}
bool in_cube (const point &p) {
	return (p.x >= min(start.x, end.x)) && (p.y >= min(start.y, end.y)) && (p.z >= min(start.z, end.z)) &&
		   (p.x <= max(start.x, end.x)) && (p.y <= max(start.y, end.y)) && (p.z <= max(start.z, end.z));
}
bool in_sphere (const sphere &s, const point &p) {
	return dist_point(s.c, p) < s.r;
}
double percentage () {
	point close;
	double d, polluted = 0.0, line;
	bool start_inside, end_inside;
	for (int i=0; i<n; i++) {
		start_inside = in_sphere(spheres[i], start);
		end_inside = in_sphere(spheres[i], end);
		if (start_inside && end_inside) {
			return 1.00;
		} else {
			close = closest_point(spheres[i].c, start, end);
			cerr<<"close: ("<<close.x<<", "<<close.y<<", "<<close.z<<")"<<endl;
			d = dist_point(close, spheres[i].c);
			if (start_inside) {
				line = sqrt(spheres[i].r*spheres[i].r - d*d);
				if (start != close) {
					if (in_cube(close)) {
						line += dist_point(close, start);
					} else {
						line -= dist_point(close, start);
					}
				}
				polluted += line;
			} else if (end_inside) {
				line = sqrt(spheres[i].r*spheres[i].r - d*d);
				if (end != close) {
					if (in_cube(close)) {
						line += dist_point(close, end);
					} else {
						line -= dist_point(close, end);
					}
				} 
				polluted += line;
			} else {
				if ((d <= spheres[i].r) && in_cube(close)) {
					line = sqrt(spheres[i].r*spheres[i].r - d*d)*2.0;
					polluted += line;
				}
			}
		}
	}
	return polluted / dist_point(start, end);
}

int main () {
	int TC, i, j;
	
	cerr.precision(2);
	cerr<<fixed;
	while (cin>>city) {
		cin>>start.x>>start.y>>start.z;
		cin>>end.x>>end.y>>end.z;
		cin>>n;
		spheres.clear();
		for (i=0; i<n; i++) {
			cin>>p.x>>p.y>>p.z>>r;
			spheres.push_back(sphere(p, (double)r));
		}
		printf("%s\n", city.c_str());
		if (start == end) {
			printf("0.00\n");
		} else {
			printf("%.02lf\n", percentage()*100.0);
		}
	}
	
	return 0;
}
