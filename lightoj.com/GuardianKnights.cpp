/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1243
        Name: Guardian Knights
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
#define MAXN 500
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, m, k, km[50], u, v, w, in, out, s, t, father[MAXN], fatherEdge[MAXN], dis[MAXN];
viiii adj[500]; // pair<pair<vértice destino, arista back>, pair<capacidad, costo> >
string mat[50];
map<ii, int> mill;

void bfs (int x, int y, int idx) {
	queue<ii> q; q.push(MP(x, y));
	ii act;
	int i, j, w, z, d, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, millIdx;
	bool vis[50][50];
	memset(vis, 0, sizeof vis);
	vis[x][y] = true;
	int dis[50][50];
	dis[x][y] = 0;
	adj[s].push_back(MP(MP(idx, adj[idx].size()), MP(km[idx], 0)));
	adj[idx].push_back(MP(MP(s, adj[s].size()-1), MP(0, 0)));
	while (q.size()) {
		act = q.front(); q.pop();
		x = act.first; y = act.second;
		for (d=0; d<4; d++) {
			w = x + dx[d]; z = y + dy[d];
			if (mat[w][z] != '#' && !vis[w][z]) {
				dis[w][z] = dis[x][y] + 1;
				q.push(ii(w, z));
				vis[w][z] = true;
				if (mat[w][z] == 'm') {
					millIdx = mill[ii(w, z)];
					adj[idx].push_back(MP(MP(millIdx, adj[millIdx].size()), MP(1, dis[w][z])));
					adj[millIdx].push_back(MP(MP(idx, adj[idx].size()-1), MP(0, -dis[w][z])));
				}
			}
		}
	}
}

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

int mcmf () {
	int mf = 0, mc = 0;
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
		for (i=0; i<MAXN; i++) adj[i].clear();
		cin>>n>>k>>m;
		s = k + m; t = s + 1;
		for (i=0; i<n; i++) cin>>mat[i];
		for (i=0; i<k; i++) cin>>km[i];
		mill.clear();
		for (i=0; i<n; i++) for (j=0; j<n; j++) if (mat[i][j] == 'm') {
			mill[MP(i, j)] = m-1+k;
			adj[m-1+k].push_back(MP(MP(t, adj[t].size()), MP(1, 0)));
			adj[t].push_back(MP(MP(m-1+k, adj[m-1+k].size()), MP(0, 0)));
			m--;
		}
		for (i=0; i<n; i++) for (j=0; j<n; j++) if (mat[i][j] >= 'A' && mat[i][j] <= 'A'+k-1) bfs(i, j, mat[i][j]-'A');
		cout<<"Case "<<it<<": "<<mcmf()<<endl;
	}
	
	return 0;
}
