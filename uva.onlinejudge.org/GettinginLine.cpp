/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=152
        Name: Getting in Line
        Date: 06/01/2015
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

int n, x, y, next[8][1<<8], limit;
double graph[8][8], DP[8][1<<8];
ii first;
vector<ii> points;

double dist_point (ii a, ii b) {
	return sqrt((double)((b.first - a.first)*(b.first - a.first)+(b.second - a.second)*(b.second - a.second)));
}

void make_graph () {
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			graph[i][j] = graph[j][i] = dist_point(points[i], points[j]) + 16.0;
		}
		graph[i][i] = 0.0;
	}
}

double dp (int idx, int bitmask) {
	if (bitmask == limit) {
		next[idx][bitmask] = -1;
		return 0.0;
	}
	if (DP[idx][bitmask] != -0.5)
		return DP[idx][bitmask];
	double ans = MAX_DBL, aux;
	for (int i=0; i<n; i++) {
		if ((bitmask & (1 << i)) == 0) {
			aux = dp(i, bitmask|(1<<i)) + graph[idx][i];
			if (aux < ans) {
				ans = aux;
				next[idx][bitmask] = i;
			}
		}
	}
	return DP[idx][bitmask] = ans;
}

void print (int idx, int bitmask) {
	if (next[idx][bitmask] != -1) {
		printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.02lf feet.\n", points[idx].first, points[idx].second, points[next[idx][bitmask]].first, points[next[idx][bitmask]].second, graph[idx][next[idx][bitmask]]);
		print(next[idx][bitmask], bitmask|(1<<next[idx][bitmask]));
	}
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC = 1, i, j, k;
	
	while (scanf("%d", &n), n) {
		points.clear();
		for (i=0; i<n; i++) {
			scanf("%d %d", &x, &y);
			points.push_back(ii(x, y));
		}
		limit = (1<<n)-1;
		make_graph();
		double ans = MAX_DBL, aux;
		int first;
		for (i=0; i<n; i++)
			for (j=0; j<(1<<n); j++)
				DP[i][j] = -0.5;
		for (i=0; i<n; i++) {
			aux = dp(i, (1<<i));
			if (aux < ans) {
				ans = aux;
				first = i;
			}
		}
		printf("**********************************************************\nNetwork #%d\n", TC++);
		print(first, (1<<first));
		printf("Number of feet of cable required is %.02lf.\n", ans);
	}
	
	return 0;
}
