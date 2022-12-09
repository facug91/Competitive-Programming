/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=878
        Name: Electric Reconfiguration
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
#define MOD 1000000007
//#define MAXN 3000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

struct point {
	int x, y;
	point () {x = y = 0;}
	point(int _x, int _y) : x(_x), y(_y) {};
};

int n, x, y;
vector<point> points;
vector<double> slopes;

int solve () {
	int i, j, k, ans = 2, aux;
	double m0, m1;
	slopes.assign(n, 0.0);
	for (i=0; i<n; i++) {
		for (j=i+1; j<n; j++) {
			slopes[j] = ((points[i].x == points[j].x) ? 1.0 : ((double)(points[i].y-points[j].y)/(double)(points[i].x-points[j].x)));
		}
		for (j=i+1; j<n; j++) {
			aux = 2;
			for (k=j+1; k<n; k++) {
				if (fabs(slopes[j] - slopes[k]) < EPS) aux++;
			}
			if (aux > ans) ans = aux;
		}
	}
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>n, n) {
		points.clear();
		for (i=0; i<n; i++) {
			cin>>x>>y;
			points.push_back(point(x, y));
		}
		cout<<solve()<<endl;
	}
	
	return 0;
}
