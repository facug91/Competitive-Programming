/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2191
        Name: Rub Task
        Date: 12/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, mat[105][105], dis[10500];
bool vis[10500];
vii adj[10500];

void make_graph () {
	int i, j, d, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, x, y;
	for (i=0; i<n*m; i++) adj[i].clear();
	for (i=0; i<n; i++) {
		for (j=0; j<m; j++) {
			for (d=0; d<4; d++) {
				x = i + dx[d];
				y = j + dy[d];
				if (x >= 0 && x < n && y >= 0 && y < m) adj[i*m+j].push_back(ii(x*m+y, mat[x][y]));
			}
		}
	}
}

void dijkstra () {
	ii act; int u, v, i;
	for (i=0; i<n*m; i++) dis[i] = INF, vis[i] = false;
	dis[0] = 0;
	priority_queue<ii, vii, greater<ii> > q; q.push(ii(0, 0));
	while (q.size()) {
		act = q.top(); q.pop();
		u = act.second;
		if (vis[u]) continue;
		if (u == n*m-1) return;
		vis[u] = true;
		for (i=0; i<adj[u].size(); i++) {
			v = adj[u][i].first;
			if (dis[v] > dis[u]+adj[u][i].second) {
				dis[v] = dis[u]+adj[u][i].second;
				q.push(ii(dis[v], v));
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, j;
	
	cin>>n>>m; m+=2;
	for (i=0; i<n; i++) mat[i][0] = mat[i][m-1] = 0;
	for (i=0; i<n; i++) for (j=1; j<m-1; j++) cin>>mat[i][j];
	make_graph();
	dijkstra();
	cout<<dis[n*m-1]<<"\n";
	
	return 0;
}
