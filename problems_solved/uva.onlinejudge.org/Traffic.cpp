/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1390
        Name: Traffic
        Date: 21/05/2015
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

int n, b[205], r, u, v, dis[205], q;
vii adj[205];
bool inuse[205], vis[205];

void mark (int u) {
	inuse[u] = true;
	for (int i=0; i<adj[u].size(); i++) {
		int v = adj[u][i].first;
		if (!inuse[v]) mark(v);
	}
}

void dfs (int u) {
	vis[u] = true;
	dis[u] = -1;
	for (int i=0; i<adj[u].size(); i++) {
		int v = adj[u][i].first;
		if (!vis[v]) dfs(v);
	}
}

void bellmanFord () {
	int i, j, u, v, w;
	for (i=0; i<n; i++) dis[i] = INF;
	dis[0] = 0;
	for (i=0; i<n-1; i++)
		for (u=0; u<n; u++) if (inuse[u])
			for (j=0; j<adj[u].size(); j++) {
				v = adj[u][j].first;
				w = adj[u][j].second;
				if (dis[v] > dis[u] + w) {
					dis[v] = dis[u] + w;
				}
			}
	queue<int> q;
	for (u=0; u<n; u++) if (inuse[u])
		for (j=0; j<adj[u].size(); j++) {
			v = adj[u][j].first;
			w = adj[u][j].second;
			if (dis[v] > dis[u] + w) q.push(v);
		}
	memset(vis, 0, sizeof vis);
	while (q.size()) {
		dfs(q.front());
		q.pop();
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	while (cin>>n) {
		for (i=0; i<205; i++) adj[i].clear();
		for (i=0; i<n; i++) cin>>b[i];
		cin>>r;
		for (i=0; i<r; i++) {
			cin>>u>>v; u--; v--;
			adj[u].push_back(ii(v, (b[v]-b[u])*(b[v]-b[u])*(b[v]-b[u])));
		}
		memset(inuse, 0, sizeof inuse);
		mark(0);
		bellmanFord();
		cin>>q;
		cout<<"Set #"<<tc++<<"\n";
		for (i=0; i<q; i++) {
			cin>>v; v--;
			if (dis[v] < 3 || dis[v] == INF) cout<<"?\n";
			else cout<<dis[v]<<"\n";
		}
	}
	
	return 0;
}
