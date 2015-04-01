/*
        By: facug91
        From: http://www.spoj.com/problems/TRAFFICN/
        Name: Traffic Network
        Date: 10/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

struct cmp {
	bool operator() (const ii &a, const ii &b) {
		return a.second > b.second;
	}
};

int n, m, k, s, t, x, y, l, dis[2][10005];
vii adj[2][10005];
vector<iii> twr;
bool vis[10005];

void dijkstra (int s, int t, int idx) {
	priority_queue<ii, vii, cmp> q;
	q.push(ii(s, 0));
	for (int i=0; i<n; i++) dis[idx][i] = INF, vis[i] = false;
	dis[idx][s] = 0;
	ii act;
	int u, v;
	while (q.size()) {
		act = q.top(); q.pop();
		u = act.first;
		if (vis[u]) continue;
		vis[u] = true;
		for (int i=0; i<adj[idx][u].size(); i++) {
			v = adj[idx][u][i].first;
			if (!vis[v] && dis[idx][v] > dis[idx][u]+adj[idx][u][i].second) {
				dis[idx][v] = dis[idx][u] + adj[idx][u][i].second;
				q.push(ii(v, dis[idx][v]));
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n>>m>>k>>s>>t; s--; t--;
		for (i=0; i<n; i++) adj[0][i].clear(), adj[1][i].clear();
		for (i=0; i<m; i++) {
			cin>>x>>y>>l; x--; y--;
			adj[0][x].push_back(ii(y, l));
			adj[1][y].push_back(ii(x, l));
		}
		twr.clear();
		for (i=0; i<k; i++) {
			cin>>x>>y>>l; x--; y--;
			twr.push_back(iii(l, ii(x, y)));
		}
		dijkstra(s, t, 0);
		dijkstra(t, s, 1);
		int ans = dis[0][t];
		for (i=0; i<k; i++) {
			ans = min(ans, dis[0][twr[i].second.first]+dis[1][twr[i].second.second]+twr[i].first);
			ans = min(ans, dis[0][twr[i].second.second]+dis[1][twr[i].second.first]+twr[i].first);
		}
		if (ans == INF) cout<<"-1\n";
		else cout<<ans<<"\n";
	}
	
	return 0;
}
