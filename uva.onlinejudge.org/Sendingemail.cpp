/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927
        Name: Sending email
        Date: 14/04/2015
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
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, s, t, u, v, w, dis[20005], ans;
bool vis[20005];
vii adj[20005];

void dijkstra () {
	int i, j;
	for (i=0; i<n; i++) dis[i] = INF, vis[i] = false;
	dis[s] = 0;
	priority_queue<ii, vii, greater<ii> > pq;
	pq.push(ii(0, s));
	ii u, v;
	while (pq.size()) {
		u = pq.top(); pq.pop();
		if (!vis[u.second]) {
			vis[u.second] = true;
			for (i=0; i<adj[u.second].size(); i++) {
				v = adj[u.second][i];
				if (dis[v.first] > dis[u.second]+v.second) {
					dis[v.first] = dis[u.second]+v.second;
					pq.push(ii(dis[v.first], v.first));
				}
			}
		}
	}
	ans = dis[t];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n>>m>>s>>t;
		for (i=0; i<n; i++) adj[i].clear();
		for (i=0; i<m; i++) {
			cin>>u>>v>>w;
			adj[u].push_back(ii(v, w));
			adj[v].push_back(ii(u, w));
		}
		dijkstra();
		if (ans != INF) cout<<"Case #"<<it<<": "<<ans<<"\n";
		else cout<<"Case #"<<it<<": unreachable\n";
	}
	
	return 0;
}
