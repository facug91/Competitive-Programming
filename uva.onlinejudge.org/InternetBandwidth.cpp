/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=761
        Name: Internet Bandwidth
        Date: 12/01/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
#define MAXN 105

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m, s, t, u, v, w, mf, f, res[105][105], level[105];
vector<int> ady[105];

bool bfs () {
	memset(level, -1, sizeof level);
	level[s] = 0;
	queue<int> q; q.push(s);
	int u, v;
	while (!q.empty()) {
		u = q.front(); q.pop();
		if (level[u] == level[t]) return true;
		for (v=0; v<(int)ady[u].size(); v++) {
			if (level[ady[u][v]] == -1 && res[u][ady[u][v]] > 0) {
				level[ady[u][v]] = level[u] + 1;
				q.push(ady[u][v]);
			}
		}
	}
	return level[t] != -1;
}

int dfs (int u, int min_edge) {
	if (u == t) return min_edge;
	int faux, fsum = 0;
	for (int v=0; v<(int)ady[u].size(); v++) {
		if ((res[u][ady[u][v]] > 0) && ((level[u] + 1) == level[ady[u][v]])) {
			faux = dfs(ady[u][v], min(min_edge, res[u][ady[u][v]]));
			if (faux) {
				fsum += faux; 
				min_edge -= faux;
				res[u][ady[u][v]] -= faux;
				res[ady[u][v]][u] += faux;
			}
		}
	}
	
	return fsum;
}

int max_flow () {
	mf = 0;
	while (bfs())
		mf += dfs(s, MAX_INT);
	return mf;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC = 1, i, j, k;
	
	while (cin>>n, n) {
		memset(res, 0, sizeof res);
		for (i=1; i<=n; i++)
			ady[i].clear();
		cin>>s>>t>>m;
		for (i=0; i<m; i++) {
			cin>>u>>v>>w;
			ady[u].push_back(v);
			ady[v].push_back(u);
			res[u][v] += w;
			res[v][u] += w;
		}
		cout<<"Network "<<TC++<<endl;
		cout<<"The bandwidth is "<<max_flow()<<"."<<endl<<endl;
	}
	
	return 0;
}
