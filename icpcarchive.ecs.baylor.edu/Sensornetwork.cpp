/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2961
        Name: Sensor network
        Date: 12/05/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, u, v, w, tail, ans;
vector<iii> edges;
list<ii> adj[355];
bool vis[355], cycle, endcycle;
multiset<int> wedge;
iii to_erase;

void dfs (int u, int f) {
	vis[u] = true;
	int v, i;
	for (list<ii>::iterator itr=adj[u].begin(); itr!=adj[u].end(); itr++) {
		v = (*itr).first;
		if (v == f) continue;
		if (!vis[v]) {
			dfs(v, u);
			if (cycle) {
				if (!endcycle) {
					if (to_erase.first > (*itr).second)
						to_erase = iii((*itr).second, ii(u, v));
					if (tail == u) endcycle = true;
				}
				return;
			} 
		} else {
			tail = v;
			cycle = true;
			endcycle = false;
			to_erase = iii((*itr).second, ii(u, v));
			return;
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	while (cin>>n, n) {
		cin>>m;
		edges.clear();
		for (i=0; i<m; i++) {
			cin>>u>>v>>w;
			edges.push_back(iii(w, ii(u, v)));
		}
		sort(edges.begin(), edges.end());
		for (i=0; i<n; i++) adj[i].clear();
		wedge.clear();
		ans = INT_MAX;
		for (i=0; i<edges.size(); i++) {
			memset(vis, 0, sizeof vis);
			adj[edges[i].second.first].push_back(ii(edges[i].second.second, edges[i].first));
			adj[edges[i].second.second].push_back(ii(edges[i].second.first, edges[i].first));
			wedge.insert(edges[i].first);
			cycle = false;
			dfs(edges[i].second.first, -1);
			if (cycle) {
				for (list<ii>::iterator itr=adj[to_erase.second.first].begin(); itr!=adj[to_erase.second.first].end(); itr++) {
					if ((*itr).first == to_erase.second.second) {
						adj[to_erase.second.first].erase(itr);
						break;
					}
				}
				for (list<ii>::iterator itr=adj[to_erase.second.second].begin(); itr!=adj[to_erase.second.second].end(); itr++) {
					if ((*itr).first == to_erase.second.first) {
						adj[to_erase.second.second].erase(itr);
						break;
					}
				}
				wedge.erase(wedge.find(to_erase.first));
			}
			if (wedge.size() == n-1) ans = min(ans, (*(--wedge.end()))-(*(wedge.begin())));
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
