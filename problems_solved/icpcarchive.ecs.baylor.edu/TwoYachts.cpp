/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4917
	Name: Two Yachts
	Date: 28/04/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define next sbjkdfh329re9fdshfd98fyh
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

int n, s, s2, t, t2, l, r, p, father[20010], fatherEdge[20010], dis[20010];
vector<pair<int, ii> > seg;
vector<pair<ii, ii> > adj[20010];

bool SPFA () {
	int i, j, u, v, cap, cos;
	ii act;
	for (i=0; i<n; i++) dis[i] = INF;
	dis[s] = 0;
	queue<ii> q; q.push(ii(0, s));
	while (q.size()) {
		act = q.front(); q.pop();
		u = act.S;
		if (act.F > dis[u]) continue;
		for (i=0; i<adj[u].size(); i++) {
			v = adj[u][i].F.F;
			cap = adj[u][i].S.F;
			cos = adj[u][i].S.S;
			if (cap > 0 && dis[v] > dis[u] + cos) {
				dis[v] = dis[u] + cos;
				father[v] = u;
				fatherEdge[v] = i;
				q.push(ii(dis[v], v));
			}
		}
	}
	return dis[t] != INF;
}

ii dfs (int u, int minEdge) {
	if (u == s) return ii(minEdge, 0);
	ii ans = dfs(father[u], min(minEdge, adj[father[u]][fatherEdge[u]].S.F));
	adj[father[u]][fatherEdge[u]].S.F -= ans.F;
	adj[u][adj[father[u]][fatherEdge[u]].F.S].S.F += ans.F;
	return MP(ans.F, ans.S+(adj[father[u]][fatherEdge[u]].S.S*ans.F));
}

int mcmf () {
	int mf = 0, mc = 0;
	ii ans;
	while (SPFA()) {
		ans = dfs(t, INT_MAX);
		mc += ans.S;
		mf += ans.F;
	}
	return mc;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n;
		s = n * 2;
		t = n * 2 + 1;
		s2 = n * 2 + 2;
		t2 = n * 2 + 3;
		adj[s].clear();
		adj[s2].clear();
		adj[t].clear();
		adj[t2].clear();
		adj[s].push_back(MP(MP(s2, 0), MP(2, 0)));
		adj[s2].push_back(MP(MP(s, 0), MP(0, 0)));
		adj[t2].push_back(MP(MP(t, 0), MP(2, 0)));
		adj[t].push_back(MP(MP(t2, 0), MP(0, 0)));
		seg.clear();
		for (i=0; i<n; i++) {
			cin>>l>>r>>p;
			seg.push_back(MP(p, MP(l, r)));
			int in = i * 2;
			int out = i * 2 + 1;
			adj[in].clear();
			adj[out].clear();
			
			adj[s2].push_back(MP(MP(in, adj[in].size()), MP(1, 0)));
			adj[in].push_back(MP(MP(s2, adj[s2].size()-1), MP(0, 0)));
			
			adj[in].push_back(MP(MP(out, adj[out].size()), MP(1, -p)));
			adj[out].push_back(MP(MP(in, adj[in].size()-1), MP(0, p)));
			
			adj[out].push_back(MP(MP(t2, adj[t2].size()), MP(1, 0)));
			adj[t2].push_back(MP(MP(out, adj[out].size()-1), MP(0, 0)));
			
		}
		for (i=0; i<n; i++) for (j=0; j<n; j++) if (seg[i].S.S < seg[j].S.F) {
			int u = i * 2 + 1;
			int v = j * 2;
			
			adj[u].push_back(MP(MP(v, adj[v].size()), MP(1, 0)));
			adj[v].push_back(MP(MP(u, adj[u].size()-1), MP(0, 0)));
		}
		n = n * 2 + 4;
		cout<<-mcmf()<<endl;
	}
	
	return 0;
}
