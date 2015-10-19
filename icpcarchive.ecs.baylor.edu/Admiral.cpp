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

int n, m, v, u, in, out, w, s, t, father[2020], fatherEdge[2020], dis[2020], orig, dest;
vector<pair<ii, ii> > adj[2020];

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

int mcmf () {
	int mf = 0, mc = 0;
	pair<int, int> ans;
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
	int i, j;
	
	while (cin>>n>>m) {
		orig = 0; dest = n-1; n *= 2;
		for (i=0; i<2020; i++) adj[i].clear();
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
			adj[out].push_back(make_pair(make_pair(in, (int)adj[in].size()), make_pair(1, w)));
			adj[in].push_back(make_pair(make_pair(out, (int)adj[out].size()), make_pair(0, -w)));
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
