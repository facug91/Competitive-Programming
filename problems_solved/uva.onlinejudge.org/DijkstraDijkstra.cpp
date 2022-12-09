/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1747
        Name: Dijkstra, Dijkstra.
        Date: 23/08/2015
*/
 
#include <bits/stdc++.h>
#define y1 		nd03dnqwuidg1odbnw9uddu0132d
#define clock 	asoudh219udhjdgausdhs9udy433
#define left	dfgag34gsfaf342rf23fgwrf42ff
#define middle	lk78k6ujkj76kjk88kkummnhh456
#define right	apidwcojbl213f80sjb3y8efjfas
//#define endl "\n"
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

int n, m, v, u, w, s, t, father[15000], fatherEdge[15000], dis[15000], orig, dest;
vector<pair<ii, ii> > adj[15000];

bool bellmanFord () {
	memset(father, -1, sizeof father);
	int i, j, u, v, cap, cos;
	for (i=0; i<n; i++) dis[i] = INF;
	dis[s] = 0;
	for (i=0; i<n-1; i++) {
		for (u=0; u<n; u++) {
			for (j=0; j<adj[u].size(); j++) {
				v = adj[u][j].first.first;
				cap = adj[u][j].second.first;
				cos = adj[u][j].second.second;
				if (cap > 0 && dis[v] > dis[u] + cos) {
					dis[v] = dis[u] + cos;
					father[v] = u;
					fatherEdge[v] = j;
				}
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
	pair<int, int> ans;
	while (bellmanFord()) {
		ans = dfs(t, INT_MAX);
		mc += ans.second;
		mf += ans.first;
	}
	return ii(mf, mc);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	while (cin>>n, n) {
		cin>>m;
		orig = 0; dest = n-1;
		for (i=0; i<15000; i++) adj[i].clear();
		for (i=0; i<m; i++) {
			cin>>u>>v>>w; u--; v--;
			adj[u].push_back(make_pair(make_pair(v, adj[v].size()), make_pair(1, w)));
			adj[v].push_back(make_pair(make_pair(u, adj[u].size()-1), make_pair(0, -w)));
			adj[v].push_back(make_pair(make_pair(u, adj[u].size()), make_pair(1, w)));
			adj[u].push_back(make_pair(make_pair(v, adj[v].size()-1), make_pair(0, -w)));
		}
		s = n++; t = n++;
		adj[s].push_back(make_pair(make_pair(orig, adj[orig].size()), make_pair(2, 0)));
		adj[orig].push_back(make_pair(make_pair(s, adj[s].size()-1), make_pair(0, 0)));
		adj[dest].push_back(make_pair(make_pair(t, adj[t].size()), make_pair(2, 0)));
		adj[t].push_back(make_pair(make_pair(dest, adj[dest].size()-1), make_pair(0, 0)));
		ii ans = mcmf();
		if (ans.first == 2) cout<<ans.second<<endl;
		else cout<<"Back to jail"<<endl;
	}
	
	return 0;
}
