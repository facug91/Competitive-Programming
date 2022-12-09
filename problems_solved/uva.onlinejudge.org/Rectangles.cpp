/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2320
        Name: Rectangles
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

int n, x, y, w, z;
pair<point, point> ans;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>n;
		cin>>ans.first.x>>ans.first.y>>ans.second.x>>ans.second.y;
		for (i=1; i<n; i++) {
			cin>>x>>y>>w>>z;
			ans.first.x = max(ans.first.x, x);
			ans.first.y = max(ans.first.y, y);
			ans.second.x = min(ans.second.x, w);
			ans.second.y = min(ans.second.y, z);
		}
		if (ans.first.x >= ans.second.x || ans.first.y >= ans.second.y) printf("Case %d: 0\n", it);
		else printf("Case %d: %d\n", it, (ans.second.x - ans.first.x) * (ans.second.y - ans.first.y));
	}
	
	return 0;
}
