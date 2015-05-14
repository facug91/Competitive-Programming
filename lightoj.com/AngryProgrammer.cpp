/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1177
        Name: Angry Programmer
        Date: 01/05/2015
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

int n, m, u, v, w, s, t, res[200][200], level[200];
vi adj[200];

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
		if (level[v] == level[u] + 1 && res[u][v] > 0) {
			faux = dfs(v, min(min_edge, res[u][v]));
			if (faux) {
				fsum += faux;
				res[u][v] -= faux;
				res[v][u] += faux;
				min_edge -= faux;
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
		cin>>n>>m;
		s = 1; t = n*2;
		for (i=0; i<t+1; i++) adj[i].clear();
		memset(res, 0, sizeof res);
		for (i=2; i<=n-1; i++) {
			cin>>w;
			adj[i*2].push_back(i*2-1);
			adj[i*2-1].push_back(i*2);
			res[i*2][i*2-1] = w;
		}
		for (i=0; i<m; i++) {
			cin>>u>>v>>w;
			adj[u*2-1].push_back(v*2);
			adj[v*2].push_back(u*2-1);
			res[u*2-1][v*2] += w;
			adj[v*2-1].push_back(u*2);
			adj[u*2].push_back(v*2-1);
			res[v*2-1][u*2] += w;
		}
		cout<<"Case "<<it<<": "<<max_flow()<<"\n";
	}
	
	return 0;
}
