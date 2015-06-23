/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2023
        Name: Matrix Decompressing
        Date: 15/05/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000003ll
//#define MAXN 5000050

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;

int r, c, s, t, rs[25], cs[25], res[55][55], level[55];
vi adj[55];

bool bfs () {
	queue<int> q; q.push(s);
	memset(level, -1, sizeof level);
	level[s] = 0;
	int u, v;
	while (q.size()) {
		u = q.front(); q.pop();
		for (int i=0; i<adj[u].size(); i++) {
			v = adj[u][i];
			if (level[v] == -1 && res[u][v] > 0) {
				level[v] = level[u] + 1;
				q.push(v);
				if (v == t) return true;
			}
		}
	}
	return false;
}

int dfs (int u, int min_edge) {
	if (u == t) return min_edge;
	int v, faux, fsum = 0;
	for (int i=0; i<adj[u].size(); i++) {
		v = adj[u][i];
		if (level[v] == level[u] + 1 && res[u][v] > 0) {
			faux = dfs(v, min(min_edge, res[u][v]));
			if (faux) {
				fsum += faux;
				res[u][v] -= faux;
				res[v][u] += faux;
				min_edge -= faux;
				if (min_edge == 0) break;
			}
		}
	}
	return fsum;
}

int max_flow () {
	int mf = 0;
	while (bfs()) mf += dfs(s, INT_MAX);
	return mf;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>r>>c;
		for (i=0; i<r; i++) cin>>rs[i];
		for (j=0; j<c; j++) cin>>cs[j];
		for (i=r-2; i>=0; i--) rs[i+1] -= rs[i];
		for (j=c-2; j>=0; j--) cs[j+1] -= cs[j];
		for (i=0; i<55; i++) adj[i].clear();
		s = r + c; t = s + 1;
		memset(res, 0, sizeof res);
		for (i=0; i<r; i++) for (j=r; j<c+r; j++) {
			adj[i].push_back(j);
			adj[j].push_back(i);
			res[i][j] = 19;
			res[j][i] = 0;
		}
		for (i=0; i<r; i++) {
			adj[s].push_back(i);
			adj[i].push_back(s);
			res[s][i] = rs[i]-c;
			res[i][s] = 0;
		}
		for (j=r; j<c+r; j++) {
			adj[j].push_back(t);
			adj[t].push_back(j);
			res[j][t] = cs[j-r]-r;
			res[t][j] = 0;
		}
		max_flow();
		cout<<"Matrix "<<it<<"\n";
		for (i=0; i<r; i++) {
			cout<<res[r][i]+1;
			for (j=r+1; j<c+r; j++) cout<<" "<<res[j][i]+1;
			cout<<"\n";
		}
		cout<<"\n";
	}
	
	return 0;
}
