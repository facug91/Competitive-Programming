/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1154
        Name: Penguins
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

int n, x, y, p, m, np, s, t, res[250][250], res2[250][205], level[250], pos[250][2];
double d;
vi adj[250];

double dist (int i, int j) {
	return sqrt((double)((pos[i][0]-pos[j][0])*(pos[i][0]-pos[j][0])+(pos[i][1]-pos[j][1])*(pos[i][1]-pos[j][1])));
}

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
	int tc, i, j, k;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n>>d;
		memset(res2, 0, sizeof res2);
		for (i=0; i<n*2; i++) adj[i].clear();
		s = 0;
		np = 0;
		for (i=1; i<=n; i++) {
			cin>>x>>y>>p>>m;
			pos[i][0] = x;
			pos[i][1] = y;
			adj[i].push_back(i+n);
			adj[i+n].push_back(i);
			res2[i][i+n] = m;
			adj[s].push_back(i);
			adj[i].push_back(s);
			res2[s][i] = p;
			np += p;
		}
		for (i=1; i<=n; i++) for (j=i+1; j<=n; j++) if (dist(i, j) <= d+EPS) {
			adj[i+n].push_back(j);
			adj[j].push_back(i+n);
			res2[i+n][j] = INT_MAX;
			adj[j+n].push_back(i);
			adj[i].push_back(j+n);
			res2[j+n][i] = INT_MAX;
		}
		cout<<"Case "<<it<<":";
		bool ok = false;
		for (k=1; k<=n; k++) {
			t = k;
			for (i=0; i<=n+n; i++) for (j=0; j<=n+n; j++) res[i][j] = res2[i][j];
			if (np == max_flow()) {
				cout<<" "<<k-1;
				ok = true;
			}
		}
		if (!ok) cout<<" -1\n";
		else cout<<"\n";
	}
	
	return 0;
}
