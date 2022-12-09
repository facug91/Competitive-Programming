/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2442
        Name: Reservoir logs
        Date: 26/11/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

struct point {
	int x, y;
	point () {x = y = 0;}
	point (int _x, int _y) : x(_x), y(_y) {};
};

int n, x, y, w;
double initialp, initial, spent, falling, total;
vector<point> P;

double area () {
	ll ans = 0ll, x1, y1, x2, y2;
	for (int i=0; i<(int)P.size()-1; i++) {
		x1 = P[i].x; x2 = P[i+1].x;
		y1 = P[i].y; y2 = P[i+1].y;
		ans += (x1 * y2 - x2 * y1);
	}
	return abs(ans) * 0.5;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n;
		P.clear();
		for (i=0; i<n; i++) {
			cin>>x>>y;
			P.push_back(point(x, y));
		}
		P.push_back(P[0]);
		cin>>w;
		cin>>initialp>>spent>>falling;
		double total = area() * w;
		initial = initialp * total / 100.0;
		if (initial < spent) {
			printf("Lack of water. ");
			initial = 0.0;
		} else {
			initial -= spent;
		}
		if (initial+falling > total) {
			printf("Excess of water. ");
			initial = total;
		} else {
			initial += falling;
		}
		printf("Final percentage: %d%%\n", (int)floor(initial*100.0/total));
		
	}
	
	return 0;
}
