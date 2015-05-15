/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1405
        Name: The Great Escape
        Date: 14/05/2015
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

int n, m, in, out, x, y, u, v, res[20020][6], t, s[20020], adj[20020][6], dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, total;
vi sadj;
string mat[105];
ii parent[20020];

bool bfs () {
	queue<int> q;
	for (int i=0; i<=n*m*2; i++) parent[i] = ii(-1, -1);
	for (int i=0; i<sadj.size(); i++) if (s[sadj[i]] > 0) {
		q.push(sadj[i]);
		parent[sadj[i]] = ii(-1, sadj[i]);
	}
	int u, v;
	while (q.size()) {
		u = q.front(); q.pop();
		for (int i=5; i>=0; i--) if (adj[u][i] != -1) {
			v = adj[u][i];
			if (parent[v].first == -1 && res[u][i] > 0) {
				parent[v] = ii(u, i);
				q.push(v);
				if (v == t) return true;
			}
		}
	}
	return false;
}

void dfs (int v, int u) {
	if (v == -1) {
		s[u] = 0;
	} else {
		dfs(parent[v].first, parent[v].second);
		if (v != t) {
			res[v][u]--;
			res[adj[v][u]][(u+2)%4]++;
		}
	}
}

int max_flow () {
	int mf = 0;
	while (bfs()) {
		mf++;
		dfs(t, -1);
	}
	return mf;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(2); //cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j, d;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		memset(adj, -1, sizeof adj);
		memset(res, 0, sizeof res);
		memset(s, 0, sizeof s);
		sadj.clear();
		cin>>n>>m;
		for (i=0; i<n; i++) cin>>mat[i];
		total = 0;
		
		//adjacents
		for (i=0; i<n; i++) for (j=0; j<m; j++) for (d=0; d<4; d++) {
			x = i + dx[d]; y = j + dy[d];
			if (x >= 0 && x < n && y >= 0 && y < m && mat[x][y] != '*') {
				u = i*m+j+n*m; v = x*m+y;
				adj[u][d] = v;
				adj[v][(d+2)%4] = u;
				res[u][d] = 1;
			}
		}
		
		//vertex splitting
		for (i=0; i<n; i++) for (j=0; j<m; j++) if (mat[i][j] != '*') {
			in = i*m+j; out = i*m+j+n*m;
			adj[in][4] = out;
			adj[out][4] = in;
			res[in][4] = 1;
		}
		
		//sink to people
		for (i=0; i<n; i++) for (j=0; j<m; j++) {
			if (mat[i][j] == '*') {
				s[i*m+j+n*m] = 1;
				sadj.push_back(i*m+j+n*m);
				total++;
			}
		}
		
		//border to sink
		t = n*m+n*m;
		for (i=0; i<n; i++) {
			adj[i*m+n*m][5] = t;
			res[i*m+n*m][5] = 1;
			adj[i*m+m-1+n*m][5] = t;
			res[i*m+m-1+n*m][5] = 1;
		}
		for (i=0; i<m; i++) {
			adj[i+n*m][5] = t;
			res[i+n*m][5] = 1;
			adj[(n-1)*m+i+n*m][5] = t;
			res[(n-1)*m+i+n*m][5] = 1;
		}
		if (max_flow() == total) cout<<"Case "<<it<<": yes\n";
		else cout<<"Case "<<it<<": no\n";
	}
	
	return 0;
}
