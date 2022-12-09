/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=5238
        Name: Coin Swap
        Date: 14/04/2016
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
//#define MOD 1000000007ll
#define MAXN 100000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, m, s, t, u, v, c[505], d[505], father[505], fatherEdge[505];
int dis[505], to_new[505];

vector<int> adj2[505];
vector<pair<ii, ii> > adj[505];

void bfs (int start) {
	queue<int> q; q.push(start);
	memset(dis, -1, sizeof dis);
	dis[start] = 0;
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v : adj2[u]) {
			if (dis[v] < 0) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
}

bool SPFA () {
	int i, j, u, v, cap, cos;
	ii act;
	for (i=0; i<n; i++) dis[i] = INF;
	dis[s] = 0;
	queue<ii> q; q.push(ii(0, s));
	while (q.size()) {
		act = q.front(); q.pop();
		u = act.second;
		if (act.first > dis[u]) continue;
		for (i=0; i<adj[u].size(); i++) {
			v = adj[u][i].first.first;
			cap = adj[u][i].second.first;
			cos = adj[u][i].second.second;
			if (cap > 0 && dis[v] > dis[u] + cos) {
				dis[v] = dis[u] + cos;
				father[v] = u;
				fatherEdge[v] = i;
				q.push(ii(dis[v], v));
			}
		}
	}
	return (dis[t] != INF);
}

ii dfs (int u, int minEdge) {
	if (u == s) return ii(minEdge, 0);
	ii ans = dfs(father[u], min(minEdge, adj[father[u]][fatherEdge[u]].second.first));
	adj[father[u]][fatherEdge[u]].second.first -= ans.first;
	adj[u][adj[father[u]][fatherEdge[u]].first.second].second.first += ans.first;
	return make_pair(ans.first, ans.second+(adj[father[u]][fatherEdge[u]].second.second*ans.first));
}

ii mcmf () {
	int mf = 0, mc = 0;
	ii ans;
	while (SPFA()) {
		ans = dfs(t, INT_MAX);
		mc += ans.second;
		mf += ans.first;
	}
	return ii(mf, mc);
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	s = 0;
	t = 1;
	cin>>tc;
	while (tc--) {
		int n2;
		cin>>n2>>m;
		for (i=0; i<n2; i++) adj2[i].clear();
		for (i=0; i<m; i++) {
			cin>>u>>v; u--; v--;
			adj2[u].push_back(v);
			adj2[v].push_back(u);
		}
		for (i=0; i<n2; i++) cin>>c[i];
		for (i=0; i<n2; i++) cin>>d[i];
		adj[s].clear();
		adj[t].clear();
		n = 2;
		for (i=0; i<n2; i++) if (c[i] != d[i]) {
			adj[n].clear();
			to_new[i] = n++;
		}
		for (i=0; i<n2; i++) if (c[i] != d[i]) {
			if (c[i] == 0) {
				bfs(i);
				for (j=0; j<n2; j++) if (c[j] != d[j] && c[i] != c[j]) {
					//cerr<<"i "<<i<<" j "<<j<<" cost "<<dis[to_new[j]]<<endl;
					adj[to_new[i]].emplace_back(ii(to_new[j], adj[to_new[j]].size()), ii(n2, dis[j]));
					adj[to_new[j]].emplace_back(ii(to_new[i], adj[to_new[i]].size()-1), ii(0, -dis[j]));
				}
			}
			if (c[i] == 0) {
				adj[s].emplace_back(ii(to_new[i], adj[to_new[i]].size()), ii(1, 0));
				adj[to_new[i]].emplace_back(ii(s, adj[s].size()-1), ii(0, 0));
			} else {
				adj[to_new[i]].emplace_back(ii(t, adj[t].size()), ii(1, 0));
				adj[t].emplace_back(ii(to_new[i], adj[to_new[i]].size()-1), ii(0, 0));
			}
		}
		ii ans = mcmf();
		cout<<ans.second<<endl;
	}
	
	return 0;
}
