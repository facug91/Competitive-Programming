/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=807
        Name: Intersecting line segments
        Date: 11/11/2014
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
	int x, y;
	point () {x = y = 0;}
	point (int _x, int _y) : x(_x), y(_y) {};
};
struct vec {
	int x, y;
	vec () {x = y = 0;}
	vec (int _x, int _y) : x(_x), y(_y) {};
	vec (point &a, point &b) {
		x = b.x-a.x;
		y = b.y-a.y;
	}
};

int n, ans;
point p1, p2;
vector<pair<point, point> > segment;

int cross (const vec &v1, const vec &v2) {
	return v1.x * v2.y - v1.y * v2.x;
}
int ccw (point &p, point &q, point &r) {
	int c = cross(vec(p, q), vec(p, r));
	return (c == 0) ? 0 : (c > 0) ? 1 : -1;
}

void check_intersection (pair<point, point> &s1, pair<point, point> &s2) {
	int turn11 = ccw(s1.first, s1.second, s2.first);
	int turn12 = ccw(s1.first, s1.second, s2.second);
	int turn21 = ccw(s2.first, s2.second, s1.first);
	int turn22 = ccw(s2.first, s2.second, s1.second);
	
	if (turn11 == 0 && turn12 == 0) {
		return;
	} else if (turn11 == 0 || turn12 == 0) {
		if (turn21 != turn22) {
			ans++;
		}
	} else if (turn21 == 0 || turn22 == 0) {
		if (turn11 != turn12) {
			ans++;
		}
	} else if (turn11 != turn12 && turn21 != turn22) {
		ans += 2;
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		segment.clear();
		cin>>n;
		while (n--) {
			cin>>p1.x>>p1.y>>p2.x>>p2.y;
			segment.push_back(make_pair(p1, p2));
		}
		ans = (int)segment.size();
		for (i=0; i<(int)segment.size()-1; i++)
			for (j=i+1; j<(int)segment.size(); j++)
				check_intersection(segment[i], segment[j]);
		cout<<ans<<endl;
		if (TC) cout<<endl;
	}
	
	return 0;
}
