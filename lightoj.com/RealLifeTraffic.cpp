/*
        By: facug91
        From: http://lightoj.com/volume_showproblem.php?problem=1291
        Name: Real Life Traffic
        Date: 29/08/2015
*/
 
#include <bits/stdc++.h>
#define y1 nd03dnqwuidg1odbnw9uddu0132d
#define EPS 1e-9
#define MP make_pair
#define DB(x) cerr << "#" << (#x) << ": " << (x);
#define DBL(x) cerr << "#" << (#x) << ": " << (x) << endl;
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
#define MOD 4294967296ll
//#define MAXN 1001
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, m, u, v;
vi adj[10005], tree[10005];

int dfstime, dfsnum[10005], dfslow[10005], ncomp, comp[10005], father[10005];
stack<int> stk;
bool vis[10005];

void scc (int u) {
  int i, v, w;
  dfsnum[u] = dfstime;
  dfslow[u] = dfstime++;
  stk.push(u);
  for (i = 0; i < adj[u].size(); i++) {
    v = adj[u][i];
    if (father[u] == v) continue;
    if (dfsnum[v] < 0) {
		father[v] = u;
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

void buildTree (int u) {
	vis[u] = true;
	for (int i=0; i<adj[u].size(); i++) {
		int v = adj[u][i];
		if (!vis[v]) {
			if (comp[u] != comp[v]) {
				tree[comp[u]].push_back(comp[v]);
				tree[comp[v]].push_back(comp[u]);
			}
			buildTree(v);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
    //cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n>>m;
		for (i=0; i<n; i++) adj[i].clear(), tree[i].clear();
		for (i=0; i<m; i++) {
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		memset(comp, -1, sizeof comp);
		memset(dfsnum, -1, sizeof dfsnum);
		memset(dfslow, -1, sizeof dfslow);
		ncomp = dfstime = 0; father[0] = -1;
		scc(0);
		memset(vis, 0, sizeof vis);
		buildTree(0);
		int ans = 0;
		for (i=0; i<n; i++) if (tree[i].size() == 1) ans++;
		cout<<"Case "<<it<<": "<<ans/2+(ans%2==1)<<endl;
	}
	
	return 0;
}
