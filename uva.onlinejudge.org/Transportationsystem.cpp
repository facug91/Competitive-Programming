/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2169
        Name: Transportation system
        Date: 13/05/2015
*/

#include <bits/stdc++.h>
#define left oiufg3782fdbeiwfdt2389dfa
#define right jsadh93dbh9d3hdgsakhdg973dh
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000003ll
#define MAXN 5000050

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, point[1005][2], p[1005], disjoint_sets, nstate;
double r, d, ans;
vi adj[1005], state[1005];
vector<pair<double, ii> > edges;
bool vis[1005];

double dist (int i, int j) {
	return hypot((double)(point[i][0]-point[j][0]), (double)(point[i][1]-point[j][1]));
}

int find_set (int i) {return (i == p[i]) ? i : (p[i] = find_set(p[i]));}

void union_set (int i, int j, double w) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		disjoint_sets--;
		ans += w;
		p[x] = y;
	}
}

void dfs (int u) {
	vis[u] = true;
	state[nstate].push_back(u);
	for (int i=0; i<adj[u].size(); i++) if (!vis[adj[u][i]]) dfs(adj[u][i]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j, k, l;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n>>r;
		edges.clear();
		for (i=0; i<n; i++) {
			cin>>point[i][0]>>point[i][1];
			adj[i].clear(); state[i].clear(); 
		}
		for (i=0; i<n; i++) for (j=i+1; j<n; j++) if ((d = dist(i, j)) <= r) {
			adj[i].push_back(j);
			adj[j].push_back(i);
			edges.push_back(make_pair(d, ii(i, j)));
		}
		sort(edges.begin(), edges.end());
		for (i=0; i<n; i++) p[i] = i; disjoint_sets = n; ans = 0.0;
		for (i=0; i<edges.size(); i++) union_set(edges[i].second.first, edges[i].second.second, edges[i].first);
		cout<<"Case #"<<it<<": "<<disjoint_sets<<" "<<(int)floor(ans+0.5);
		memset(vis, 0, sizeof vis);
		nstate = 0;
		for (i=0; i<n; i++) if (!vis[i]) {
			dfs(i);
			nstate++;
		}
		edges.clear();
		for (i=0; i<nstate; i++) for (j=i+1; j<nstate; j++)
			for (k=0; k<state[i].size(); k++) for (l=0; l<state[j].size(); l++)
				edges.push_back(make_pair(dist(state[i][k], state[j][l]), ii(i, j)));
		sort(edges.begin(), edges.end());
		for (i=0; i<n; i++) p[i] = i; disjoint_sets = nstate; ans = 0.0;
		for (i=0; i<edges.size(); i++) union_set(edges[i].second.first, edges[i].second.second, edges[i].first);
		cout<<" "<<(int)floor(ans+0.5)<<"\n";
	}
	
	return 0;
}
