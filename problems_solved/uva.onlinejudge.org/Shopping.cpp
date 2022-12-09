/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2913
        Name: Shopping
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

int n, m, u, v, s, limit, idx[11];
ll w, dis[11][11], dis2[100005], DP[11][1<<11];
vector<pair<int, ll> > adj[100005];
unordered_map<int, int> store;
priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
bool vis[100005];

void dijkstra (int origin) {
	int i, j, u, v;
	ll w;
	pair<ll, int> curr;
	for (i=0; i<n; i++) {
		dis2[i] = LLONG_MAX;
		vis[i] = false;
	}
	dis[origin][origin] = 0ll;
	dis2[idx[origin]] = 0ll;
	pq.push(MP(0ll, idx[origin]));
	while (pq.size()) {
		curr = pq.top(); pq.pop();
		u = curr.S;
		if (vis[u]) continue;
		if (store.find(u) != store.end()) dis[origin][store[u]] = dis2[u];
		vis[u] = true;
		for (pair<int, ll> node : adj[u]) {
			v = node.F;
			w = node.S;
			if (dis2[v] > dis2[u] + w) {
				dis2[v] = dis2[u] + w;
				pq.push(MP(dis2[v], v));
			}
		}
	}
}

ll dp (int u, int bm) {
	if (DP[u][bm] != -1ll) return DP[u][bm];
	if (bm == limit) return DP[u][bm] = dis[u][0];
	ll ans = LLONG_MAX;
	for (int v=0; v<s; v++) if ((bm&(1<<v)) == 0) ans = min(ans, dp(v, bm|(1<<v)) + dis[u][v]);
	return DP[u][bm] = ans;
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
		for (i=0; i<n; i++) adj[i].clear();
		for (i=0; i<m; i++) {
			cin>>u>>v>>w;
			adj[u].push_back(MP(v, w));
			adj[v].push_back(MP(u, w));
		}
		cin>>s; s++;
		store.clear();
		idx[0] = 0;
		store[0] = 0;
		for (i=1; i<s; i++) {
			cin>>u;
			idx[i] = u;
			store[u] = i;
		}
		for (i=0; i<s; i++) dijkstra(i);
		limit = (1 << s) - 1;
		for (i=0; i<s; i++) for (j=0; j<=limit; j++) DP[i][j] = -1ll;
		cout<<dp(0, 1)<<endl;
	}
	
	return 0;
}
