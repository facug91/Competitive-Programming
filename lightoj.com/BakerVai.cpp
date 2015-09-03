/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1071
        Name: Baker Vai
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

int n, m, u, v, in, out, s, t, father[22000], fatherEdge[22000], dis[22000], mat[105][105];
vector<pair<ii, ii> > adj[22000];

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
	return MP(ans.first, ans.second+(adj[father[u]][fatherEdge[u]].second.second*ans.first));
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
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		for (i=0; i<22000; i++) adj[i].clear();
		cin>>n>>m;
		for (i=0; i<n; i++) for (j=0; j<m; j++) cin>>mat[i][j];
		for (i=0; i<n; i++) {
			for (j=0; j<m; j++) {
				u = i * m + j;
				in = u * 2; out = u * 2 + 1;
				adj[in].push_back(MP(MP(out, adj[out].size()), MP(1, 0)));
				adj[out].push_back(MP(MP(in, adj[in].size()-1), MP(0, 0)));
				if (j != m-1) {
					v = i * m + j + 1;
					in = v * 2;
					adj[out].push_back(MP(MP(in, adj[in].size()), MP(1, -mat[i][j+1])));
					adj[in].push_back(MP(MP(out, adj[out].size()-1), MP(0, mat[i][j+1])));
				}
				if (i != n-1) {
					v = (i + 1) * m + j;
					in = v * 2;
					adj[out].push_back(MP(MP(in, adj[in].size()), MP(1, -mat[i+1][j])));
					adj[in].push_back(MP(MP(out, adj[out].size()-1), MP(0, mat[i+1][j])));
				}
			}
		}
		v = 0; u = (n-1) * m + (m-1);
		s = v * 2 + 1; t = u * 2;
		int n2 = n;
		n = n * m * 2 + 2;
		cout<<"Case "<<it<<": "<<abs(mcmf())+mat[0][0]-mat[n2-1][m-1]<<endl;
	}
	
	return 0;
}
