/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1858
        Name: Walk Through the Forest
        Date: 25/02/2016
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

int n, m, u, v;
ll w, dis[1005], DP[1005];
vector<pair<int, ll> > adj[1005];
bool vis[1005];

void dijkstra (int origin) {
	priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
	memset(vis, 0, sizeof vis);
	for (int i=0; i<n; i++) dis[i] = LLONG_MAX;
	dis[origin] = 0;
	pq.push(MP(0ll, origin));
	pair<ll, int> u;
	while (pq.size()) {
		u = pq.top(); pq.pop();
		if (vis[u.S]) continue;
		vis[u.S] = true;
		for (pair<int, ll> v : adj[u.S]) {
			if (dis[v.F] > dis[u.S] + v.S) {
				dis[v.F] = dis[u.S] + v.S;
				pq.push(MP(dis[v.F], v.F	));
			}
		}
	}
}

ll dp (int u) {
	if (DP[u] != -1) return DP[u];
	if (u == 1) return 1;
	ll ans = 0;
	for (auto v : adj[u]) {
		if (dis[v.F] < dis[u]) ans += dp(v.F);
	}
	return DP[u] = ans;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	while (cin>>n, n) {
		cin>>m;
		for (i=0; i<n; i++) adj[i].clear();
		for (i=0; i<m; i++) {
			cin>>u>>v>>w; u--; v--;
			adj[u].push_back(MP(v, w));
			adj[v].push_back(MP(u, w));
		}
		dijkstra(1);
		memset(DP, -1, sizeof DP);
		cout<<dp(0)<<endl;
	}
	
	return 0;
}
