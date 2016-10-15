/*
        By: facug91
        From: http://codeforces.com/gym/100818
        Name: Taxies
        Date: 04/10/2016
*/

#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define INF 1000000000

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

int n, m, t, u, v, w, bf, c, k, h[16], emp[16][16], dis[20005];
ll DP[16][1<<16][4];
priority_queue<ii, vii, greater<ii>> pq;
bool vis[20005];
vii adj[20005];
map<int, vi> to_emp;

void dijkstra (int idx) {
	int i, j;
	for (i=1; i<=n; i++) {
		dis[i] = INF;
		vis[i] = false;
	}
	dis[h[idx]] = 0;
	pq.push(ii(0, h[idx]));
	while (pq.size()) {
		ii u = pq.top(); pq.pop();
		if (vis[u.S]) continue;
		vis[u.S] = true;
		if (to_emp.count(u.S)) for (int v : to_emp[u.S]) emp[idx][v] = dis[u.S];
		for (ii v : adj[u.S]) {
			if (dis[v.F] > dis[u.S] + v.S) {
				dis[v.F] = dis[u.S] + v.S;
				pq.push(ii(dis[v.F], v.F));
			}
		}
	}
}

ll dp (int idx, int bm, int len) {
	if (bm == ((1<<k)-1)) return 0;
	if (DP[idx][bm][len] != -1) return DP[idx][bm][len];
	if (len == 4) return dp(0, bm, 0);
	ll ans = 1e15;
	for (int i=1; i<k; i++) if((bm & (1<<i)) == 0) {
		ans = min(ans, dp(i, bm|(1<<i), len+1) + emp[idx][i]);
	}
	if (idx != 0) ans = min(ans, dp(0, bm, 0));
	return DP[idx][bm][len] = ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, j;
	
	while (cin>>n>>m) {
		for (i=1; i<=n; i++) adj[i].clear();
		while (m--) {
			cin>>t>>u>>v>>w;
			adj[u].emplace_back(v, w);
			if (t == 2) adj[v].emplace_back(u, w);
		}
		cin>>bf;
		to_emp.clear();
		cin>>h[0];
		cin>>k; k++;
		for (i=1; i<k; i++) cin>>h[i];
		for (i=0; i<k; i++) to_emp[h[i]].push_back(i);
		for (i=0; i<k; i++) dijkstra(i);
		for (i=0; i<k; i++) emp[0][i] += bf;
		memset(DP, -1, sizeof DP);
		cout<<dp(0, 1, 0)<<endl;
	}
	
}
