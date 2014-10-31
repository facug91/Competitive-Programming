/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=297
        Name: Cops and Robbers
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
	point (int _x, int _y) : x(_x), y(_y) {};
	bool operator==(const point &other) {
		return x == other.x && y == other.y;
	}
	bool operator!=(const point &other) {
		return !((*this)==other);
	}
};

int c, r, o, x, y;
vector<point> cops, robbers, others, ch_c, ch_r;

point to_vec (const point &a, const point &b) {
	return point(b.x-a.x, b.y-a.y);
}
int cross (const point &v1, const point &v2) {
	return v1.x * v2.y - v1.y * v2.x;
}
bool collinear (const point &p, const point &q, const point &r) {
	return cross(to_vec(p, q), to_vec(p, r)) == 0;
}
bool ccw (const point &p, const point &q, const point &r) {
	return cross(to_vec(p, q), to_vec(p, r)) > 0;
}
double dist_point (const point &a, const point &b) {
	return hypot((double)b.x-a.x, (double)b.y-a.y);
}
bool in_segment (const point &a, const point &b, const point &c) {
	return (c.x >= min(a.x, b.x) && c.x <= max(a.x, b.x) && c.y >= min(a.y, b.y) && c.y <= max(a.y, b.y));
}

point pivot;
bool angle_cmp (const point &a, const point &b) {
	if (collinear(pivot, a, b))
		return dist_point(pivot, a) < dist_point(pivot, b);
	int d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	int d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	return atan2((double)d1y, (double)d1x) < atan2((double)d2y, (double)d2x);
}

vector<point> convex_hull (vector<point> P) {
	int i, j, n = (int)P.size();
	
	if (n == 0) return P;
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

bool in_polygon (int cant, vector<point> &P, point &p) {
	if (cant < 3) return false;
	if ((int)P.size() <= 3) return false;
	for (int i=1; i<(int)P.size(); i++) 
		if (!ccw(P[i-1], P[i], p) && !collinear(P[i-1], P[i], p)) {
			return false;
		}
	return true;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC = 1, i, j;
	
	while (cin>>c>>r>>o, c || r || o) {
		cops.clear();
		for (i=0; i<c; i++) {
			cin>>x>>y;
			cops.push_back(point(x, y));
		}
		robbers.clear();
		for (i=0; i<r; i++) {
			cin>>x>>y;
			robbers.push_back(point(x, y));
		}
		others.clear();
		for (i=0; i<o; i++) {
			cin>>x>>y;
			others.push_back(point(x, y));
		}
		
		ch_c = convex_hull(cops);
		ch_r = convex_hull(robbers);
		
		cout<<"Data set "<<TC++<<":"<<endl;
		for (i=0; i<o; i++) {
			if (in_polygon(c, ch_c, others[i])) cout<<"     Citizen at ("<<others[i].x<<","<<others[i].y<<") is safe."<<endl;
			else if (in_polygon(r, ch_r, others[i])) cout<<"     Citizen at ("<<others[i].x<<","<<others[i].y<<") is robbed."<<endl;
			else cout<<"     Citizen at ("<<others[i].x<<","<<others[i].y<<") is neither."<<endl;
		}
		cout<<endl;
	}
	
	return 0;
}
