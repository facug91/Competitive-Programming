/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=1563
        Name: Vampire Dinasty
        Date: 10/02/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, s, t, a, b, c, d, sun[1005], dist[1005];
vector<iii> adj[1005];
bool vis[1005];

struct cmp {
	bool operator() (const iii &a, const iii &b) {
		if (a.first != b.first) return a.first > b.first;
		return a.second.first > b.second.first;
	}
};

void dijkstra () {
	int u, v, i, j;
	priority_queue<iii, vector<iii>, cmp > q; q.push(iii(0, ii(0, s)));
	for (i=0; i<n; i++) sun[i] = dist[i] = INF;
	sun[s] = dist[s] = 0;
	memset(vis, 0, sizeof vis);
	while (q.size()) {
		u = q.top().second.second; q.pop();
		if (!vis[u]) {
			vis[u] = true;
			for (i=0; i<adj[u].size(); i++) {
				v = adj[u][i].first;
				if (sun[v] == sun[u] + adj[u][i].second.second) {
					if (dist[v] > dist[u] + adj[u][i].second.first) {
						dist[v] = dist[u] + adj[u][i].second.first;
						q.push(iii(sun[v], ii(dist[v], v)));
					}
				} else if (sun[v] > sun[u] + adj[u][i].second.second) {
					sun[v] = sun[u] + adj[u][i].second.second;
					dist[v] = dist[u] + adj[u][i].second.first;
					q.push(iii(sun[v], ii(dist[v], v)));
				}
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j;
	
	cin>>n>>m>>s>>t;
	for (i=0; i<m; i++) {
		cin>>a>>b>>c>>d;
		adj[a].push_back(iii(b, ii(c, c-d)));
		adj[b].push_back(iii(a, ii(c, c-d)));
	}
	dijkstra();
	cout<<dist[t]<<" "<<sun[t]<<endl;
	
	return 0;
}
