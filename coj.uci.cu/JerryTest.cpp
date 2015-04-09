/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2755
        Name: Jerry Test
        Date: 11/03/2015
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

int n, m, u, v, cc, cg;
vector<int> adj[100005];
bool vis[100005];

bool dfs (int u) {
	vis[u] = true;
	bool ans = (adj[u].size() == 2);
	for (int i=0; i<adj[u].size(); i++) {
		int v = adj[u][i];
		if (!vis[v]) ans = (dfs(v) && ans);
	}
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i;
	
	while (cin>>n>>m) {
		for (i=0; i<n; i++) adj[i].clear();
		for (i=0; i<m; i++) {
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		for (i=0; i<n; i++) vis[i] = false;
		cc = cg = 0;
		for (i=0; i<n; i++) if (!vis[i]) {
			cc++;
			if (dfs(i)) cg++;
		}
		cout<<cc<<" "<<cg<<"\n";
	}
	
	return 0;
}
