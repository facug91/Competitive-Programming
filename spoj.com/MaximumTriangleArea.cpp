/*
        By: facug91
        From: http://www.spoj.com/problems/MTRIAREA/
        Name: Maximum Triangle Area
        Number: 3931
        Date: 30/08/2014
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
//#define MAXN 6005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

struct point_i {
	int x, y;
	point_i() {x = y = 0;}
	point_i(int _x, int _y) : x(_x), y(_y) {};
	bool operator==(const point_i &other) {
		return (x==other.x) && (y==other.y);
	}
};
struct cmp {
	bool operator()(const point_i &a, const point_i &b) {
		if (a.x == b.x) return a.y < b.y;
		return a.x < b.x;
	}
}myCmp;

int n, x, y;
vector<point_i> pol, convex;

int cross3 (point_i &o, point_i &a, point_i &b) {
	return (a.x-o.x) * (b.y-o.y) - (a.y-o.y) * (b.x-o.x); }
void convex_hull () {
	int i, t, n = (int)pol.size(), k = 0;
	convex.resize(2*n);
	sort(pol.begin(), pol.end(), myCmp);
	for (i=0; i<n; i++) {
		while (k >= 2 && cross3(convex[k-2], convex[k-1], pol[i]) <= 0) k--;
		convex[k++] = pol[i];
	}
	for (i=n-1, t=k+1; i>=0; i--) {
		while (k >= t && cross3(convex[k-2], convex[k-1], pol[i]) <= 0) k--;
		convex[k++] = pol[i];
	}
	if (convex[0] == convex[k-1]) k--;
	convex.resize(k);
}

point_i to_vec (point_i &a, point_i &b) {
	return point_i(b.x-a.x, b.y-a.y); }
int cross2 (const point_i &a, const point_i &b) {
	return a.x*b.y - a.y*b.x; }
int area (point_i &a, point_i &b, point_i &c) {
	return abs(cross2(to_vec(a, b), to_vec(a, c))); }
double max_tri () {
	int a, b, c, ba, bb, bc, n = (int)convex.size();
	a = ba = 0;
	b = bb = 1;
	c = bc = 2;
	for (; a<n; a++) {
		if (a == b) b = (b+1)%n;
		if (b == c) c = (c+1)%n;
		while (true) {
			while (area(convex[a], convex[b], convex[c]) <= area(convex[a], convex[b], convex[(c+1)%n]))
				c = (c+1)%n;
			if (area(convex[a], convex[b], convex[c]) <= area(convex[a], convex[(b+1)%n], convex[c])) {
				b = (b+1)%n;
				continue;
			} else break;
		}
		if (area(convex[a], convex[b], convex[c]) > area(convex[ba], convex[bb], convex[bc]))
			ba = a, bb = b, bc = c;
	}
	return ((double) area(convex[ba], convex[bb], convex[bc])) * 0.5;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC = 1, i, j;
	
	cout.precision(2);
	cout<<fixed;
	
	while (cin>>n, n != -1) {
		pol.clear();
		for (i=0; i<n; i++) {
			cin>>x>>y;
			pol.push_back(point_i(x, y));
		}
		convex_hull();
		cout<<max_tri()<<"\n";
	}
	
	return 0;
}

