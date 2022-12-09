/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2559
        Name: Convex Hull of Lattice Points
        Date: 30/10/2014
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
	int x, y;
	point () {x = y = 0;}
	point(int _x, int _y) : x(_x), y(_y) {};
	bool operator==(const point &other) {
		return x == other.x && y == other.y;
	}
	bool operator!=(const point &other) {
		return !((*this)==other);
	}
};

int c, n, x, y;
vector<point> P, CH;

point to_vec (const point &a, const point &b) {
	return point(b.x-a.x, b.y-a.y);
}
int cross(const point &v1, const point &v2) {
	return v1.x * v2.y - v1.y * v2.x;
}
bool collinear(const point &p, const point &q, const point &r) {
	return cross(to_vec(p, q), to_vec(p, r)) == 0;
}
bool ccw (const point &p, const point &q, const point &r) {
	return cross(to_vec(p, q), to_vec(p, r)) > 0;
}
double dist_point (const point &a, const point &b) {
	return hypot((double) a.x-b.x, (double)a.y-b.y);
}
bool all_collinear () {
	for (int i=2; i<(int)P.size(); i++)
		if (!collinear(P[i-2], P[i-1], P[i]))
			return false;
	return true;
}

point pivot;
bool angle_cmp (const point &a, const point &b) {
	if (collinear(pivot, a, b))
		return dist_point(pivot, a) < dist_point(pivot, b);
	int d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	int d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	return atan2((double)d1y, (double)d1x) < atan2((double)d2y, (double)d2x);
}

void convex_hull () {
	int i, j, size = (int)P.size();
	
	if (size <= 2) {
		if (P[0] != P[size-1]) P.push_back(P[0]);
		CH = P;
		return;
	}
	
	int P0 = 0;
	for (i=1; i<size; i++)
		if ((P[P0].y > P[i].y) || (P[P0].y == P[i].y && P[P0].x < P[i].x))
			P0 = i;
	
	pivot = P[P0];
	point tmp = P[0]; P[0] = P[P0]; P[P0] = tmp;
	sort(++P.begin(), P.end(), angle_cmp);
	
	CH.push_back(P[size-1]); CH.push_back(P[0]); CH.push_back(P[1]);
	
	i = 2;
	while (i < size) {
		j = CH.size() - 1;
		if (CH.size() == 2) CH.push_back(P[i++]);
		else if (ccw(CH[j-1], CH[j], P[i])) CH.push_back(P[i++]);
		else CH.pop_back();
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		P.clear();
		CH.clear();
		cin>>c>>n;
		for (i=0; i<n; i++) {
			cin>>x>>y;
			P.push_back(point(x, y));
		}
		convex_hull();
		CH.pop_back();
		j = 0;
		for (i=1; i<(int)CH.size(); i++)
			if ((CH[j].y < CH[i].y) || (CH[j].y == CH[i].y && CH[j].x > CH[i].x))
				j = i;
		cout<<c<<" "<<(int)CH.size()<<endl;
		for (i=j; i>=0; i--)
			cout<<CH[i].x<<" "<<CH[i].y<<endl;
		for (i=(int)CH.size()-1; i>j; i--)
			cout<<CH[i].x<<" "<<CH[i].y<<endl;
	}
	
	return 0;
}
