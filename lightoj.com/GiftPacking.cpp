/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1222
        Name: Gift Packing
        Date: 25/08/2015
*/
 
#include <bits/stdc++.h>
#define y1 		nd03dnqwuidg1odbnw9uddu0132d
#define clock 	asoudh219udhjdgausdhs9udy433
#define left	dfgag34gsfaf342rf23fgwrf42ff
#define middle	lk78k6ujkj76kjk88kkummnhh456
#define right	apidwcojbl213f80sjb3y8efjfas
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define DEB(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 4294967296ll
//#define MAXN 1001
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, u, v, s, t, p[55][55], res[110][110], cost[110][110], dis[110], father[110];
vi adj[110];

bool SPFA () {
	int i, u, v;
	ii act;
	for (i=0; i<n; i++) dis[i] = INF;
	dis[s] = 0;
	queue<ii> q; q.push(ii(0, s));
	while (q.size()) {
		act = q.front(); q.pop();
		u = act.second;
		if (act.first > dis[u]) continue;
		for (i=0; i<adj[u].size(); i++) {
			v = adj[u][i];
			if (act.first > dis[u]) continue;
			if (res[u][v] > 0 && dis[v] > dis[u] + cost[u][v]) {
				dis[v] = dis[u] + cost[u][v];
				father[v] = u;
				q.push(ii(dis[v], v));
			}
		}
	}
	return dis[t] != INF;
}

ii dfs (int u, int minEdge) {
	if (u == s) return ii(minEdge, 0);
	int v = father[u];
	ii ans = dfs(v, min(minEdge, res[v][u]));
	res[v][u] -= ans.first;
	res[u][v] += ans.first;
	return ii(ans.first, ans.second+(cost[v][u]*ans.first));
}

int mcmf () {
	int mf = 0,  mc = 0;
	ii ans;
	while (SPFA()) {
		ans = dfs(t, INT_MAX);
		mc += ans.second;
		mf += ans.first;
	}
	return mc;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		for (i=0; i<110; i++) adj[i].clear();
		memset(res, 0, sizeof res);
		memset(cost, 0, sizeof cost);
		cin>>n;
		s = n + n; t = s + 1;
		for (i=0; i<n; i++) {
			u = i;
			adj[s].push_back(u);
			adj[u].push_back(s);
			res[s][u] = 1;
			cost[u][v] = 0;
			cost[v][u] = 0;
			for (j=0; j<n; j++) {
				cin>>p[i][j];
				v = j + n;
				adj[u].push_back(v);
				adj[v].push_back(u);
				res[u][v] = 1;
				cost[u][v] = 1000-p[i][j];
				cost[v][u] = -(1000-p[i][j]);
			}
			v = u + n;
			adj[v].push_back(t);
			adj[t].push_back(v);
			res[v][t] = 1;
			cost[v][t] = 0;
			cost[t][v] = 0;
		}
		n = n + n + 2;
		mcmf();
		int ans = 0;
		n = (n - 2) / 2;
		for (u=0; u<n; u++) for (v=n; v<n+n; v++) if (res[v][u] == 1) ans += (1000-cost[u][v]);
		cout<<"Case "<<it<<": "<<ans<<"\n";
	}
	
	return 0;
}
