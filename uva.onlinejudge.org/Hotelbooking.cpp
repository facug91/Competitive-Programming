/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2682
        Name: Hotel booking
        Date: 01/03/2016
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

int n, h, m, u, v, w, hotel[105], to_hotel[10005], dis[10005];
vii adj[10005];
vi adj2[105];
priority_queue<ii, vii, greater<ii> > pq;
queue<int> q;
bool vis[10005];

void dijkstra (int idx) {
	int i, j;
	for (i=0; i<n; i++) {
		dis[i] = INF;
		vis[i] = false;
	}
	pq.push(ii(0, idx));
	dis[idx] = 0;
	ii u;
	while (pq.size()) {
		u = pq.top(); pq.pop();
		if (vis[u.S]) continue;
		vis[u.S] = true;
		for (ii v : adj[u.S]) {
			if (dis[v.F] > dis[u.S] + v.S) {
				dis[v.F] = dis[u.S] + v.S;
				pq.push(ii(dis[v.F], v.F));
			}
		}
	}
}

void bfs (int idx) {
	int i, j;
	for (i=0; i<h; i++) {
		dis[i] = 0;
		vis[i] = false;
	}
	vis[idx] = true;
	q.push(idx);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v : adj2[u]) {
			if (!vis[v]) {
				dis[v] = dis[u] + 1;
				q.push(v);
				vis[v] = true;
			}
		}
	}
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	while (cin>>n, n) {
		for (i=0; i<n; i++) adj[i].clear();
		cin>>h;
		memset(to_hotel, -1, sizeof to_hotel);
		for (i=0; i<h; i++) {
			cin>>hotel[i];
			hotel[i]--;
			to_hotel[hotel[i]] = i;
		}
		to_hotel[0] = h;
		hotel[h++] = 0;
		to_hotel[n-1] = h;
		hotel[h++] = n-1;
		cin>>m;
		for (i=0; i<m; i++) {
			cin>>u>>v>>w; u--; v--;
			adj[u].push_back(ii(v, w));
			adj[v].push_back(ii(u, w));
		}
		for (i=0; i<h; i++) {
			adj2[i].clear();
			dijkstra(hotel[i]);
			for (j=0; j<n; j++) if (j != hotel[i] && to_hotel[j] != -1 && dis[j] <= 600) adj2[i].push_back(to_hotel[j]);
		}
		bfs(h-2);
		cout<<dis[h-1]-1<<endl;
	}
	
	return 0;
}
