/*
        By: facug91
        From: http://www.spoj.com/ranks/CIRCUITS/
        Name: Circuits
        Date: 29/08/2015
*/
 
#include <bits/stdc++.h>
#define y1 		d03dnqwuidg1odbnw9uddu0132d
#define count 	asljdhalsdbajlsdbasljd78v7f
#define EPS 1e-9
#define MP make_pair
#define DB(x) cerr << " #" << (#x) << ": " << (x);
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl;
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
#define MOD 4294967296ll
//#define MAXN 1001
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, m, u, v, ans, ansOne, ansTwo, parity[2], count;
vi adj[10005], tree[10005];

int dfstime, dfsnum[105], dfslow[105], ncomp, comp[105], compSize[105], father[105];
stack<int> stk;
bool vis[105], vis2[105];

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
      compSize[ncomp]++;
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

void countLeaves (int u) {
	vis2[u] = true;
	if (tree[u].size() == 1) {
		count++;
		int v = tree[u][0];
		if (tree[v].size() == 1) {
			if (compSize[u] > 1 && compSize[v] > 1) count = 0;
			else if (compSize[u] == 1 && compSize[v] == 1) count = -2;
			else {
				count = 0;
				ans++;
				return;
			}
			return;
		}
	} else if (tree[u].size() == 0) {
		if (compSize[u] > 1) count = 0;
		else count = -1;
		return;
	}
	for (int i=0; i<tree[u].size(); i++) {
		int v = tree[u][i];
		if (!vis2[v]) countLeaves(v);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
    //cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	while (cin>>n>>m, n != -1) {
		for (i=0; i<n; i++) adj[i].clear(), tree[i].clear();
		for (i=0; i<m; i++) {
			cin>>u>>v; u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		memset(comp, -1, sizeof comp);
		memset(compSize, 0, sizeof compSize);
		memset(dfsnum, -1, sizeof dfsnum);
		memset(dfslow, -1, sizeof dfslow);
		memset(vis, 0, sizeof vis);
		memset(vis2, 0, sizeof vis2);
		ncomp = dfstime = parity[0] = parity[1] = ans = ansOne = ansTwo = 0;
		for (i=0; i<n; i++) if (comp[i] == -1) {
			father[i] = -1;
			scc(i);
			buildTree(i);
			count = 0;
			countLeaves(comp[i]);
			if (count < 0) {
				if (count == -1) ansOne++;
				else ansTwo++;
			} else {
				parity[count%2]++;
				ans += (count/2+(count%2==1));
			}
		}
		if (ans == 0) {
			if (ansOne > 0) {
				if (ansTwo == 0 && ansOne < 3) ans++;
			} else {
				if (ansTwo > 0 && ansTwo < 2) ans++;
			}
		}
		cout<<ans-(parity[1]/2)+ansOne+ansTwo<<endl;
	}
	
	return 0;
}
