/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2318
        Name: Isolated Segments
        Date: 13/11/2014
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

struct point {
	double x, y;
	point () {x = y = 0.0;}
	point (double _x, double _y) : x(_x), y(_y) {};
};
struct segment {
	point b, e;
	segment () {}
	segment (point _b, point _e) : b(_b), e(_e) {};
};

int n, ans;
segment seg[105];

point to_vec (const point &a, const point &b) {
	return point(b.x-a.x, b.y-a.y);
}
double cross (const point &a, const point &b) {
	return a.x*b.y - a.y*b.x;
}
int direction (const point &p, const point &q, const point &r) {
	double d = cross(to_vec(p, q), to_vec(p, r));
	return (fabs(d) < EPS) ? 0 : (d > 0.0) ? 1 : -1;
}
bool in_segment (const segment &s, const point p) {
	return (min(s.b.x, s.e.x) <= p.x) && (min(s.b.y, s.e.y) <= p.y) && (max(s.e.x, s.b.x) >= p.x) && (max(s.e.y, s.b.y) >= p.y);
}
bool intersect (const segment &s1, const segment &s2) {
	int turn1 = direction(s1.b, s1.e, s2.b);
	int turn2 = direction(s1.b, s1.e, s2.e);
	int turn3 = direction(s2.b, s2.e, s1.b);
	int turn4 = direction(s2.b, s2.e, s1.e);
	
	if (turn1 == 0 && turn2 == 0) {
		return (in_segment(s1, s2.b) || in_segment(s1, s2.e) || in_segment(s2, s1.b) || in_segment(s2, s1.e));
	} else if (turn1 == 0 || turn2 == 0) {
		return (turn3 == 0 || turn4 == 0) || (turn3 != turn4);
	}else if (turn3 == 0 || turn4 == 0) {
		return (turn1 != turn2);
	}
	return (turn1 != turn2) && (turn3 != turn4);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n;
		for (i=0; i<n; i++)
			cin>>seg[i].b.x>>seg[i].b.y>>seg[i].e.x>>seg[i].e.y;
		ans = 0;
		for (i=0; i<n; i++) {
			bool isolated = true;
			for (j=0; j<n && isolated; j++) {
				if (i != j && intersect(seg[i], seg[j])) {
					isolated = false;
				}
			}
			if (isolated) ans++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
