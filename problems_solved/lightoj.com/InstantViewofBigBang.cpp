/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1108
        Name: Instant View of Big Bang
        Date: 22/05/2015
*/
 
#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10000100
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, m, u, v, w, dis[1005];
vii adj[1005], adjt[1005];
bool vertex[1005], start[1005];

void dfs (int u) {
	start[u] = true;
	for (int i=0; i<adj[u].size(); i++) {
		int v = adj[u][i].first;
		if (!start[v]) dfs(v);
	}
}

bool bellmanFord () {
	int i, j, u, v, w;
	for (j=0; j<n; j++) dis[j] = INF;
	dis[n] = 0;
	for (j=0; j<n; j++)
		for (u=0; u<=n; u++)
			for (i=0; i<adj[u].size(); i++) {
				v = adj[u][i].first;
				w = adj[u][i].second;
				if (dis[v] > dis[u] + w)
					dis[v] = dis[u] + w;
			}
	memset(vertex, 0, sizeof vertex);
	for (u=0; u<n; u++)
		for (i=0; i<adj[u].size(); i++) {
			v = adj[u][i].first;
			w = adj[u][i].second;
			if (dis[v] > dis[u] + w)
				vertex[u] = vertex[v] = true;
		}
	memset(start, 0, sizeof start);
	bool ans = true;
	for (i=0; i<n; i++) if (vertex[i]) {
		dfs(i);
		ans = false;
	}
	return ans;
}

int main () {
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n>>m;
		for (i=0; i<=n; i++) adj[i].clear();
		for (i=0; i<n; i++) adj[n].push_back(ii(i, 0));
		for (i=0; i<m; i++) {
			cin>>u>>v>>w;
			adj[v].push_back(ii(u, w));
		}
		cout<<"Case "<<it<<":";
		if (bellmanFord()) cout<<" impossible\n";
		else {
			for (i=0; i<n; i++) if (start[i]) cout<<" "<<i;
			cout<<"\n";
		}
	}
	
	return 0;
}
