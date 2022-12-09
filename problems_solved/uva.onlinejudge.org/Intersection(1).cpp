/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=127
        Name: Intersection
        Date: 24/02/2015
*/

#include <bits/stdc++.h>
#define y0 asljdhasasdajld
#define y1 asljdhasasda13d
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

struct point {
	int x, y;
	point () {x = y = 0;}
	point (int _x, int _y) {
		x = _x; y = _y;
	}
};

int x0, y0, x1, y1, l, t, r, b;
int DEBBUG = 0;

point to_vec (const point &a, const point &b) {
	return point(b.x-a.x, b.y-a.y);
}

int cross (const point &a, const point &b) {
	int ans = a.x * b.y - a.y * b.x;
	if (ans == 0) return 0;
	if (ans < 0) return -1;
	else return 1;
}

bool inside (const point &p, const point &q, const point &r) {
	return (r.x >= min(p.x, q.x)) && (r.x <= max(p.x, q.x)) && (r.y >= min(p.y, q.y)) && (r.y <= max(p.y, q.y));
}

bool intersect (const point &p1, const point &p2, const point &p3, const point &p4) {
	int d1 = cross(to_vec(p1, p2), to_vec(p1, p3));
	int d2 = cross(to_vec(p1, p2), to_vec(p1, p4));
	int d3 = cross(to_vec(p3, p4), to_vec(p3, p1));
	int d4 = cross(to_vec(p3, p4), to_vec(p3, p2));
	if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
		((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) return true;
	if ((d1 == 0 && inside(p1, p2, p3)) || (d2 == 0 && inside(p1, p2, p4)) ||
		(d3 == 0 && inside(p3, p4, p1)) || (d4 == 0 && inside(p3, p4, p2))) return true;
	return false;
}

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>x0>>y0>>x1>>y1>>l>>t>>r>>b;
		if (l > r) swap(l, r);
		if (b > t) swap(b, t);
		if (inside(point(l, b), point(r, t), point(x0, y0)) || inside(point(l, b), point(r, t), point(x1, y1)) ||
			intersect(point(x0, y0), point(x1, y1), point(l, t), point(l, b)) ||
			intersect(point(x0, y0), point(x1, y1), point(l, t), point(r, t)) ||
			intersect(point(x0, y0), point(x1, y1), point(r, t), point(r, b)) ||
			intersect(point(x0, y0), point(x1, y1), point(l, b), point(r, b))) {
				cout<<"T"<<endl;
			} else cout<<"F"<<endl;
	}
	
	return 0;
}
