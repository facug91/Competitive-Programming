/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1405
        Name: The Great Escape
        Date: 15/05/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000003ll
//#define MAXN 5000050

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, in, out, x, y, u, v, s, t, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, total, p[20020], pa[20020];
vector<iii> adj[20020];
string mat[105];

bool bfs () {
	queue<int> q; q.push(s);
	memset(p, -1, sizeof p);
	memset(pa, -1, sizeof pa);
	int u, v, c, rev;
	bool sink = false;
	while (q.size()) {
		u = q.front(); q.pop();
		if (u == t) {
			sink = true;
			continue;
		}
		for (int i=0; i<adj[u].size(); i++) {
			v = adj[u][i].first;
			c = adj[u][i].second.first;
			rev = adj[u][i].second.second;
			if (p[v] == -1 && c > 0) {
				p[v] = u;
				pa[v] = rev;
				q.push(v);
			}
		}
	}
	return sink;
}

int dfs (int u, int min_edge) {
	if (u == s) return min_edge;
	else if (p[u] != -1) {
		int rev = adj[u][pa[u]].second.second;
		int cr = adj[p[u]][rev].second.first;
		if (cr > 0) {
			int f = dfs(p[u], min(min_edge, cr));
			if (f) {
				adj[p[u]][rev].second.first -= f;
				adj[u][pa[u]].second.first += f;
			}
			return f;
		} else return 0;
	} else return 0;
}

int max_flow () {
	int mf = 0, i, v, cr, rev;
	while (bfs()) {
		for (i=0; i<adj[t].size(); i++) {
			v = adj[t][i].first;
			rev = adj[t][i].second.second;
			cr = adj[v][rev].second.first;
			if (cr > 0) {
				p[t] = v;
				pa[t] = i;
				mf += dfs(t, cr);
			}
		}
	}
	return mf;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(2); //cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j, k;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		for (i=0; i<20020; i++) adj[i].clear();
		cin>>n>>m;
		for (i=0; i<n; i++) cin>>mat[i];
		total = 0;
		
		s = 20018; t = 20019;
		for (i=0; i<n; i++) for (j=0; j<m; j++) {
			int in = i*m+j, out = i*m+j+n*m;
			if (mat[i][j] != '*') {
				adj[in].push_back(iii(out, ii(1, adj[out].size())));
				adj[out].push_back(iii(in, ii(0, adj[in].size()-1)));
			}
			if (mat[i][j] == '*') {
				adj[s].push_back(iii(out, ii(1, adj[out].size())));
				adj[out].push_back(iii(s, ii(0, adj[s].size()-1)));
				total++;
			}
			if (i == 0 || j == 0 || i == n-1 || j == m-1) {
				adj[out].push_back(iii(t, ii(1, adj[t].size())));
				adj[t].push_back(iii(out, ii(0, adj[out].size()-1)));
			}
			for (k=0; k<4; k++) {
				x = i + dx[k]; y = j + dy[k];
				if (x >= 0 && y >= 0 && x < n && y < m && mat[x][y] != '*') {
					u = x*m+y;
					adj[out].push_back(iii(u, ii(1, adj[u].size())));
					adj[u].push_back(iii(out, ii(0, adj[out].size()-1)));
				} 
			}
		}
		
		if (max_flow() == total) cout<<"Case "<<it<<": yes\n";
		else cout<<"Case "<<it<<": no\n";
	}
	
	return 0;
}
