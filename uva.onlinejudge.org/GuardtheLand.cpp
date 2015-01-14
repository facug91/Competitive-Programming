/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2686
        Name: Guard the Land
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
	int x, y;
	point () {x = y = 0;}
	point (int _x, int _y) : x(_x), y(_y) {};
};

int n, x, y, w, z, area_w0, area_w1, area_s, area_t;
pair<point, point> zone[3];

int main () {
	//ios_base::sync_with_stdio(0);
	int TC = 1, i, j;
	
	cin>>n;
	while (n--) {
		cin>>x>>y>>w>>z;
		zone[0] = make_pair(point(x, y), point(w, z));
		cin>>x>>y>>w>>z;
		zone[1] = make_pair(point(x, y), point(w, z));
		zone[2] = make_pair(point(max(zone[0].first.x, zone[1].first.x), max(zone[0].first.y, zone[1].first.y)), 
							point(min(zone[0].second.x, zone[1].second.x), min(zone[0].second.y, zone[1].second.y)));
		if (zone[2].first.x >= zone[2].second.x || zone[2].first.y >= zone[2].second.y) area_s = 0;
		else area_s = (zone[2].second.x-zone[2].first.x) * (zone[2].second.y-zone[2].first.y);
		area_w0 = (zone[0].second.x-zone[0].first.x) * (zone[0].second.y-zone[0].first.y) - area_s;
		area_w1 = (zone[1].second.x-zone[1].first.x) * (zone[1].second.y-zone[1].first.y) - area_s;
		area_t = 100 * 100 - (area_w0 + area_w1 + area_s);
		printf("Night %d: %d %d %d\n", TC++, area_s, area_w0+area_w1, area_t);
	}
	
	return 0;
}
