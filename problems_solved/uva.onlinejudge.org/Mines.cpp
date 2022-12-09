/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3704
        Name: Mines
        Date: 02/03/2016
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
#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, x[2005], y[2005], d[2005], dfstime, dfsnum[MAXN], dfslow[MAXN], ncomp, comp[MAXN], in[2005], ans;
bool vis[2005];
stack<int> stk;
vi adj[2005];

void scc (int u) {
  int i, v, w;
  dfsnum[u] = dfstime;
  dfslow[u] = dfstime++;
  stk.push(u);
  for (i = 0; i < adj[u].size(); i++) {
    v = adj[u][i];
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

void dfs (int u) {
	vis[u] = true;
	for (int v : adj[u]) {
		if (comp[u] != comp[v]) {
			in[comp[v]]++;
		}
		if (!vis[v]) dfs(v);
	}
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n;
		for (i=0; i<n; i++) {
			cin>>x[i]>>y[i]>>d[i];
			d[i] /= 2;
			adj[i].clear();
		}
		for (i=0; i<n; i++) for (j=0; j<n; j++) if (i != j) 
			if (abs(x[i]-x[j]) <= d[i] && abs(y[i]-y[j]) <= d[i]) adj[i].push_back(j);
		memset(comp, -1, sizeof comp);
		memset(dfsnum, -1, sizeof dfsnum);
		ncomp = dfstime = 0;
		for (i=0; i<n; i++) if (dfsnum[i] < 0) scc(i);
		memset(vis, 0, sizeof vis);
		memset(in, 0, sizeof in);
		for (i=0; i<n; i++) if (!vis[i]) dfs(i);
		ans = 0;
		for (i=0; i<ncomp; i++) if (in[i] == 0) ans++;
		cout<<ans<<endl;
	}
	
	return 0;
}
