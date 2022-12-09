/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1153
        Name: Internet Bandwidth
        Date: 30/04/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, s, t, res[105][105], u, v, w, level[105];
vi adj[105];

bool bfs () {
	queue<int> q; q.push(s);
	memset(level, -1, sizeof level);
	level[s] = 0;
	int u, v;
	while (q.size()) {
		u = q.front(); q.pop();
		for (int i=0; i<adj[u].size(); i++) {
			v = adj[u][i];
			if (level[v] == -1 && res[u][v] > 0) {
				level[v] = level[u] + 1;
				q.push(v);
				if (v == t) return true;
			}
		}
	}
	return false;
}

int dfs (int u, int min_edge) {
	if (u == t) return min_edge;
	int v, faux, fsum = 0;
	for (int i=0; i<adj[u].size(); i++) {
		v = adj[u][i];
		if (res[u][v] > 0 && level[u] + 1 == level[v]) {
			faux = dfs(v, min(min_edge, res[u][v]));
			if (faux) {
				fsum += faux;
				min_edge -= faux;
				res[u][v] -= faux;
				res[v][u] += faux;
				if (min_edge == 0) break;
			}
		}
	}
	return fsum;
}

int max_flow () {
	int mf = 0;
	while (bfs()) mf += dfs(s, INT_MAX);
	return mf;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n>>s>>t>>m; s--; t--;
		memset(res, 0, sizeof res);
		for (i=0; i<n; i++) adj[i].clear();
		for (i=0; i<m; i++) {
			cin>>u>>v>>w; u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
			res[u][v] += w;
			res[v][u] += w;
		}
		cout<<"Case "<<it<<": "<<max_flow()<<"\n";
	}
	
	return 0;
}
