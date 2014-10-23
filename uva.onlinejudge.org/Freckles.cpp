/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=975
        Name: Freckles
        Date: 20/10/2014
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

int n, p[105];
double x, y, graph[105][105], ans;
ii points[105];
vector<pair<double, ii> > edges;

double dist_point (const ii &a, const ii &b) {
	return hypot((double)(a.first-b.first),(double)(a.second-b.second));
}
int find_set (int i) {
	return (p[i] == i) ? i : p[i] = find_set(p[i]);
}
void union_set (int i, int j, double w) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		ans += w;
		p[y] = x;
	}
}
void kruskal () {
	int i, j;
	for (i=0; i<n; i++) p[i] = i;
	ans = 0.0;
	edges.clear();
	for (i=0; i<n; i++)
		for (j=i+1; j<n; j++)
			edges.push_back(make_pair(graph[i][j], ii(i, j)));
	sort(edges.begin(), edges.end());
	for (i=0; i<(int)edges.size(); i++)
		union_set(edges[i].second.first, edges[i].second.second, edges[i].first);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n;
		for (i=0; i<n; i++) {
			cin>>x>>y;
			points[i] = ii(x, y);
		}
		for (i=0; i<n; i++) {
			for (j=i+1; j<n; j++) {
				graph[i][j] = dist_point(points[i], points[j]);
			}
		}
		kruskal();
		printf("%.2lf\n", ans);
		if (TC) printf("\n");
	}
	
	return 0;
}
