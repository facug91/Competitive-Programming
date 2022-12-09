/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2960
        Name: Jumping monkey
        Date: 11/05/2015
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

int n, m, u, v, bitmask[21], father[1<<21], shoot[1<<21];
vi adj[21];
bool vis[1<<21];
stack<int> stk;

bool bfs () {
	queue<int> q; q.push((1<<n)-1);
	memset(vis, 0, sizeof vis);
	memset(father, -1, sizeof father);
	memset(shoot, -1, sizeof shoot);
	vis[(1<<n)-1] = true;
	int u, v, i, j;
	while (q.size()) {
		u = q.front(); q.pop();
		for (i=0; i<n; i++) if ((u & (1<<i)) != 0) {
			v = 0;
			for (j=0; j<n; j++) if (((u & (1<<j)) != 0) && (i != j)) v |= bitmask[j];
			if (!vis[v]) {
				vis[v] = true;
				father[v] = u;
				shoot[v] = i;
				q.push(v);
				if (v == 0) return true;
			}
		}
	}
	return false;
}

void dfs (int u) {
	if (u == ((1<<n)-1)) return;
	stk.push(shoot[u]);
	dfs(father[u]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	while (cin>>n>>m, n || m) {
		for (i=0; i<n; i++) adj[i].clear();
		memset(bitmask, 0, sizeof bitmask);
		for (i=0; i<m; i++) {
			cin>>u>>v;
			adj[u].push_back(v);
			bitmask[u] |= (1<<v);
			adj[v].push_back(u);
			bitmask[v] |= (1<<u);
		}
		if (bfs()) {
			dfs(0);
			cout<<stk.size()<<":";
			while (stk.size()) {
				cout<<" "<<stk.top();
				stk.pop();
			}
			cout<<"\n";
		} else cout<<"Impossible\n";
	}
	
	return 0;
}
