/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4162
        Name: Beehives
        Date: 16/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, u, v, ans, high[505], prev[505];
vector<int> adj[505];
bool used[505], vis[505];
queue<int> q;

int bfs (int idx) {
	int u, v, i, j, ans = INT_MAX;
	memset(vis, 0, sizeof vis);
	vis[idx] = true;
	high[idx] = 0;
	prev[idx] = -1;
	q.push(idx);
	while (q.size()) {
		u = q.front(); q.pop();
		for (i=0; i<adj[u].size(); i++) {
			v = adj[u][i];
			if (!used[v] && prev[u] != v) {
				if (!vis[v]) {
					vis[v] = true;
					high[v] = high[u] + 1;
					prev[v] = u;
					q.push(v);
				} else {
					ans = min(ans, high[v]+high[u]+1);
				}
			}
		}
	}
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>n>>m;
		for (i=0; i<n; i++) adj[i].clear();
		for (i=0; i<m; i++) {
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		ans = INT_MAX;
		memset(used, 0, sizeof used);
		for (i=0; i<n; i++) {
			ans = min(ans, bfs(i));
			used[i] = true;
		}
		cout<<"Case "<<it<<": ";
		if (ans == INT_MAX) cout<<"impossible\n";
		else cout<<ans<<"\n";
	}
	
	return 0;
}
