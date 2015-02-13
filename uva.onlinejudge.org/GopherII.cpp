/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1021
        Name: Gopher II
        Date: 14/01/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
#define MAXN 205

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m, s, v, dist[MAXN], match[MAXN], mm;
double x, y;
vector<int> ady[MAXN];
pair<double, double> gh;
vector<pair<double, double> > g;

double dist_point (const pair<double, double> &a, const pair<double, double> &b) {
	return hypot((double)(b.first-a.first), (double)(b.second-a.second));
}

bool bfs () {
	int u, v, i;
	queue<int> q;
	for (i=1; i<=n; i++)
		if (!match[i]) dist[i] = 0, q.push(i);
		else dist[i] = -1;
	dist[0] = -1;
	while (!q.empty()) {
		u = q.front(); q.pop();
		if (u != 0) {
			for (i=0; i<(int)ady[u].size(); i++) {
				v = ady[u][i];
				if (dist[match[v]] == -1) {
					dist[match[v]] = dist[u] + 1;
					q.push(match[v]);
				}
			}
		}
	}
	return dist[0] != -1;
}

bool dfs (int u) {
	if (u == 0) return true;
	int v, i;
	for (i=0; i<(int)ady[u].size(); i++) {
		v = ady[u][i];
		if (dist[match[v]] == dist[u] + 1 && dfs(match[v])) {
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	dist[u] = -1;
	return false;
}

int max_matching () {
	mm = 0;
	memset(match, 0, sizeof match);
	while (bfs()) 
		for (int i=1; i<=n; i++)
			if (!match[i] && dfs(i))
				mm++;
	return mm;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>n>>m>>s>>v) {
		for (i=0; i<n+m+1; i++)
			ady[i].clear();
		g.clear();
		for (i=0; i<n; i++) {
			cin>>x>>y;
			g.push_back(make_pair(x, y));
		}
		for (i=0; i<m; i++) {
			cin>>gh.first>>gh.second;
			for (j=0; j<n; j++)
				if (dist_point(gh, g[j]) - ((double)(s*v)) < EPS)
					ady[j+1].push_back(i+1+n);
		}
		cout<<n - max_matching()<<endl;
	}
	
	return 0;
}
