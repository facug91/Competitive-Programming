/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2299
        Name: The Largest Clique
        Date: 26/02/2016
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
#define MOD 1000000007ll
//#define MAXN 10005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, m, u, v, dfstime, dfsnum[1005], dfslow[1005], ncomp, comp[1005], compsize[1005], DP[1005];
vi adj[1005], tadj[1005], dag[1005];
bool vis[1005];
stack<int> stk;

void dfs (int u, int f) {
	vis[u] = true;
	tadj[f].push_back(u);
	for (int v : adj[u]) if (!vis[v]) dfs(v, f);
}

void scc (int u) {
  int i, v, w;
  dfsnum[u] = dfstime;
  dfslow[u] = dfstime++;
  stk.push(u);
  for (i = 0; i < tadj[u].size(); i++) {
    v = tadj[u][i];
    if (dfsnum[v] < 0) {
		scc(v); 
		dfslow[u] = min(dfslow[u], dfslow[v]);
    } else if (comp[v] < 0) dfslow[u] = min(dfslow[u], dfsnum[v]);
  }
  if (dfsnum[u] == dfslow[u]) {
    do {
      v = stk.top(); stk.pop();
      comp[v] = ncomp;
    } while (v != u);
    ncomp++;
  }
}

void make_dag (int u) {
	vis[u] = true;
	for (int v : tadj[u]) {
		if (comp[u] != comp[v]) dag[comp[u]].push_back(comp[v]);
		if (!vis[v]) make_dag(v);
	}
}

int dp (int u) {
	if (DP[u] != -1) return DP[u];
	int ans = 0;
	for (int v : dag[u]) ans = max(ans, dp(v));
	return DP[u] = ans + compsize[u];
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
		for (i=0; i<n; i++) {
			adj[i].clear();
			tadj[i].clear();
			dag[i].clear();
		}
		for (i=0; i<m; i++) {
			cin>>u>>v; u--; v--;
			adj[u].push_back(v);
		}
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++) vis[j] = false;
			dfs(i, i);
		}
		memset(comp, -1, sizeof comp);
		memset(dfsnum, -1, sizeof dfsnum);
		memset(compsize, 0, sizeof compsize);
		ncomp = dfstime = 0;
		for (i=0; i<n; i++) {
			if (dfsnum[i] < 0) scc(i);
			compsize[comp[i]]++;
		}
		memset(vis, 0, sizeof vis);
		for (i=0; i<n; i++) make_dag(i);
		vi::iterator it;
		for (i=0; i<ncomp; i++) {
			it = unique(dag[i].begin(), dag[i].end());
			dag[i].resize(distance(dag[i].begin(), it));
		}
		int ans = 0;
		memset(DP, -1, sizeof DP);
		for (i=0; i<ncomp; i++) ans = max(ans, dp(i));
		cout<<ans<<endl;
	}
	return 0;
}
