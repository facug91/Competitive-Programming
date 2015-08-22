/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4277
        Name: Admiral
        Date: 22/08/2015
*/
 
#include <bits/stdc++.h>
#define y1 		nd03dnqwuidg1odbnw9uddu0132d
#define clock 	asoudh219udhjdgausdhs9udy433
#define left	dfgag34gsfaf342rf23fgwrf42ff
#define middle	lk78k6ujkj76kjk88kkummnhh456
#define right	apidwcojbl213f80sjb3y8efjfas
#define EPS 1e-9
#define MP make_pair
#define DEB(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 4294967296ll
#define MAXN 1001
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, m, v, u, in, out, w, s, t, father[7020], fatherEdge[7020], dis[7020], orig, dest;
bool used[2005][2005];
vector<pair<ii, ii> > adj[7020];

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

int mcmf () {
	int mf = 0, mc = 0;
	pair<int, int> ans;
	while (bellmanFord()) {
		ans = dfs(t, INT_MAX);
		mc += ans.second;
		mf += ans.first;
	}
	return mc;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	while (cin>>n>>m) {
		orig = 0; dest = n-1; n *= 2;
		for (i=0; i<7020; i++) adj[i].clear();
		memset(used, 0, sizeof used);
		for (i=1; i<n/2-1; i++) {
			out = i * 2 + 1;
			in = i * 2;
			adj[in].push_back(make_pair(make_pair(out, 0), make_pair(1, 0)));
			adj[out].push_back(make_pair(make_pair(in, 0), make_pair(0, 0)));
		}
		
		out = orig * 2 + 1;
		in = orig * 2;
		adj[in].push_back(make_pair(make_pair(out, 0), make_pair(2, 0)));
		adj[out].push_back(make_pair(make_pair(in, 0), make_pair(0, 0)));
		
		out = dest * 2 + 1;
		in = dest * 2;
		adj[in].push_back(make_pair(make_pair(out, 0), make_pair(2, 0)));
		adj[out].push_back(make_pair(make_pair(in, 0), make_pair(0, 0)));
		
		for (i=0; i<m; i++) {
			cin>>u>>v>>w; u--; v--;
			out = u * 2 + 1;
			in = v * 2;
			if (used[u][v]) {
				adj[out].push_back(make_pair(make_pair(n, (int)adj[n].size()), make_pair(1, w)));
				adj[n].push_back(make_pair(make_pair(out, (int)adj[out].size()-1), make_pair(0, -w)));
				adj[n].push_back(make_pair(make_pair(in, (int)adj[in].size()), make_pair(1, w)));
				adj[in].push_back(make_pair(make_pair(n, (int)adj[n].size()-1), make_pair(0, -w)));
				n++;
			} else {
				adj[out].push_back(make_pair(make_pair(in, (int)adj[in].size()), make_pair(1, w)));
				adj[in].push_back(make_pair(make_pair(out, (int)adj[out].size()), make_pair(0, -w)));
				used[u][v] = true;
			}
		}
		s = n++; t = n++;
		in = orig * 2;
		out = dest * 2 + 1;
		adj[s].push_back(make_pair(make_pair(in, (int)adj[in].size()), make_pair(2, 0)));
		adj[in].push_back(make_pair(make_pair(s, (int)adj[s].size()-1), make_pair(0, 0)));
		adj[out].push_back(make_pair(make_pair(t, (int)adj[t].size()), make_pair(2, 0)));
		adj[t].push_back(make_pair(make_pair(out, (int)adj[out].size()-1), make_pair(0, 0)));
		cout<<mcmf()<<"\n";
	}
	
	return 0;
}
