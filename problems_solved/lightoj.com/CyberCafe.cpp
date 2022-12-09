/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1237
        Name: Cyber Cafe
        Date: 03/09/2015
*/
 
#include <bits/stdc++.h>
#define y1 		nd03dnqwuidg1odbnw9uddu0132d
#define clock 	asoudh219udhjdgausdhs9udy433
#define left	dfgag34gsfaf342rf23fgwrf42ff
#define middle	lk78k6ujkj76kjk88kkummnhh456
#define right	apidwcojbl213f80sjb3y8efjfas
#define move	df53y5fgsf43fdsfsdtg4j6hfdg4
#define count	nkwdfj111afbjdfsbj32r8yfwejb
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 4294967296ll
#define MAXN 200
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, k, g, u, v, s, t, in[100], out[100], father[MAXN], fatherEdge[MAXN], dis[MAXN];
viiii adj[MAXN]; // pair<pair<vértice destino, arista back>, pair<capacidad, costo> >

bool SPFA () {
	int i, j, u, v, cap, cos;
	ii act;
	for (i=0; i<MAXN; i++) dis[i] = INF;
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
		for (i=0; i<MAXN; i++) adj[i].clear();
		cin>>n>>k>>g;
		for (i=0; i<n; i++) cin>>in[i];
		for (i=0; i<n; i++) cin>>out[i];
		s = n + n; t = s + 1;
		for (i=0; i<n; i++) {
			v = i; u = i + n;
			adj[s].push_back(MP(MP(v, adj[v].size()), MP(1, 0)));
			adj[v].push_back(MP(MP(s, adj[s].size()-1), MP(0, 0)));
			adj[u].push_back(MP(MP(t, adj[t].size()), MP(1, 0)));
			adj[t].push_back(MP(MP(u, adj[u].size()-1), MP(0, 0)));
			u = i;
			for (j=0; j<n; j++) if (in[i] < out[j]) {
				v = j + n;
				adj[u].push_back(MP(MP(v, adj[v].size()), MP(1, min(g, (out[j]-in[i]-k)*(out[j]-in[i]-k)))));
				adj[v].push_back(MP(MP(u, adj[u].size()-1), MP(0, -min(g, (out[j]-in[i]-k)*(out[j]-in[i]-k)))));
			}
		}
		cout<<"Case "<<it<<": ";
		ii ans = mcmf();
		if (ans.first != n) cout<<"impossible"<<endl;
		else {
			cout<<ans.second<<" ";
			for (i=0; i<MAXN; i++) adj[i].clear();
			for (i=0; i<n; i++) {
				v = i; u = i + n;
				adj[s].push_back(MP(MP(v, adj[v].size()), MP(1, 0)));
				adj[v].push_back(MP(MP(s, adj[s].size()-1), MP(0, 0)));
				adj[u].push_back(MP(MP(t, adj[t].size()), MP(1, 0)));
				adj[t].push_back(MP(MP(u, adj[u].size()-1), MP(0, 0)));
				u = i;
				for (j=0; j<n; j++) if (in[i] < out[j]) {
					v = j + n;
					adj[u].push_back(MP(MP(v, adj[v].size()), MP(1, 1000-min(g, (out[j]-in[i]-k)*(out[j]-in[i]-k)))));
					adj[v].push_back(MP(MP(u, adj[u].size()-1), MP(0, -(1000-min(g, (out[j]-in[i]-k)*(out[j]-in[i]-k))))));
				}
			}
			ii ans = mcmf();
			cout<<n*1000-ans.second<<endl;
		}
	}
	
	return 0;
}
