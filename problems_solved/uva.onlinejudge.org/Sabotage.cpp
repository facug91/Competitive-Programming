/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1421
        Name: Sabotage
        Date: 07/05/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, s, t, res[55][55], level[55], u, v, w;
vi adj[55];
bool mark[55], vis[55];
queue<int> q;

bool bfs () {
    queue<int> q; q.push(s);
    memset(level, -1, sizeof level);
    level[s] = 0;
    int u, v;
    while (!q.empty()) {
        u = q.front(); q.pop();
        for (int i=0; i<(int)adj[u].size(); i++) {
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
    for (int i=0; i<(int)adj[u].size(); i++) {
        v = adj[u][i];
        if (res[u][v] > 0 && level[v] == level[u] + 1) {
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

void dfs2 (int u) {
	mark[u] = true;
	for (int i=0; i<adj[u].size(); i++) {
		int v = adj[u][i];
		if (!mark[v] && res[u][v] > 0) dfs2(v);
	}
}

void dfs3 (int u) {
	vis[u] = true;
	for (int i=0; i<adj[u].size(); i++) {
		int v = adj[u][i];
		if (!mark[v]) cout<<u+1<<" "<<v+1<<"\n";
		else if (!vis[v]) dfs3(v);
	}
}

void print () {
	memset(mark, 0, sizeof mark);
	dfs2(s);
	memset(vis, 0, sizeof vis);
	dfs3(s);
}


int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	s = 0; t = 1;
	while (cin>>n>>m, n || m) {
		for (i=0; i<n; i++) adj[i].clear();
		memset(res, 0, sizeof res);
		for (i=0; i<m; i++) {
			cin>>u>>v>>w; u--; v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
			res[u][v] = w;
			res[v][u] = w;
		}
		max_flow();
		print();
		cout<<"\n";
	}
	
	return 0;
}
