/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1251
        Name: Dog and Gopher
        Date: 18/10/2014
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
//#define MAXN 3000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

struct point {
	double x, y;
	point () {x = y = 0.0;}
	point (double _x, double _y) : x(_x), y(_y) {};
};

int n;
double x, y;
point gopher, dog, escape;
vector<point> holes;

double dist_point (const point &a, const point &b) {
	return hypot(a.x-b.x, a.y-b.y);
}

bool can_escape () {
	int i, j;
	for (i=0; i<n; i++) {
		if (dist_point(gopher, holes[i]) <= dist_point(dog, holes[i])*0.5) {
			escape.x = holes[i].x;
			escape.y = holes[i].y;
			return true;
		}
	}
	return false;
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (scanf("%d %lf %lf %lf %lf", &n, &gopher.x, &gopher.y, &dog.x, &dog.y) != EOF) {
		holes.clear();
		for (i=0; i<n; i++) {
			scanf("%lf %lf", &x, &y);
			holes.push_back(point(x, y));
		}
		if (can_escape()) {
			printf("The gopher can escape through the hole at (%.03lf,%.03lf).\n", escape.x, escape.y);
		} else {
			printf("The gopher cannot escape.\n");
		}
	}
	
	return 0;
}
