/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5240
	Name: Grid
	Date: 18/04/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 1000000007ll
#define MAXN 100000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, m, mat[55][55], sum, s, t, p[2600], pa[2600], dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
vector<pair<int, pair<int, int> > > adj[2600];
 
bool bfs () {
	int u, v, c, rev, i;
	queue<int> q; q.push(s);
	for (i=1; i<=n; i++) p[i] = pa[i] = -1;
	bool sink = false;
	while (q.size()) {
		u = q.front(); q.pop();
		if (u == t) {
			sink = true;
			continue;
		}
		for (i=0; i<adj[u].size(); i++) {
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
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n>>m;
		sum = 0;
		for (i=0; i<n; i++) for (j=0; j<m; j++) {
			cin>>mat[i][j];
			sum += mat[i][j];
		}
		for (i=0; i<n*m+2; i++) adj[i].clear();
		s = 0;
		t = 1;
		for (i=0; i<n; i++) {
			for (j=i%2; j<m; j+=2) {
				if (mat[i][j] == 0) continue;
				int u = i*m+j+2;
				adj[s].push_back(MP(u, MP(mat[i][j], adj[u].size())));
				adj[u].push_back(MP(s, MP(0, adj[s].size()-1)));
				for (int d=0; d<4; d++) {
					int x = i + dx[d];
					int y = j + dy[d];
					if (x >= 0 && x < n && y >= 0 && y < m) {
						int v = x*m+y+2;
						adj[u].push_back(MP(v, MP(1000, adj[v].size())));
						adj[v].push_back(MP(u, MP(0, adj[u].size()-1)));
					}
				}
			}
			for (j=(i+1)%2; j<m; j+=2) {
				if (mat[i][j] == 0) continue;
				int v = i*m+j+2;
				adj[v].push_back(MP(t, MP(mat[i][j], adj[t].size())));
				adj[t].push_back(MP(v, MP(0, adj[v].size()-1)));
			}
		}
		n = n*m+2;
		cout<<sum-max_flow()<<endl;
	}
	
	return 0;
}
