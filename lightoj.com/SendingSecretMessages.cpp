/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1404
        Name: Sending Secret Messages
        Date: 26/08/2015
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
typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, m, p, u, v, w, c, s, t, father[55], fatherEdge[55], dis[55];
vector<iiii> adj[55]; // pair<pair<vértice destino, arista back>, pair<capacidad, costo> >

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
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n>>m>>p;
		for (i=0; i<55; i++) adj[i].clear();
		for (i=0; i<m; i++) {
			cin>>u>>v>>c>>w; u--; v--;
			adj[u].push_back(iiii(ii(v, adj[v].size()), ii(c, w)));
			adj[v].push_back(iiii(ii(u, adj[u].size()-1), ii(0, -w)));
			adj[v].push_back(iiii(ii(u, adj[u].size()), ii(c, w)));
			adj[u].push_back(iiii(ii(v, adj[v].size()-1), ii(0, -w)));
		}
		s = 0; t = n;
		adj[n-1].push_back(iiii(ii(t, adj[t].size()), ii(p, 0)));
		adj[t].push_back(iiii(ii(n-1, adj[n-1].size()-1), ii(0, 0)));
		n++;
		ii ans = mcmf();
		if (ans.first < p) cout<<"Case "<<it<<": impossible\n";
		else cout<<"Case "<<it<<": "<<ans.second<<"\n";
	}
	
	return 0;
}
