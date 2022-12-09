/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1262
        Name: Diagonal Sum
        Date: 09/05/2015
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

int n, m, k, mn, s, t, res[250][250], level[250];
vi adj[250];

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

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		for (i=0; i<250; i++) adj[i].clear();
		memset(res, 0, sizeof res);
		cin>>n>>m;
		mn = min(n, m);
		k = n + m - 1;
		s = k+k; t = s+1;
		for (i=0; i<k; i++) {
			cin>>res[s][i];
			res[s][i] -= ((i+1<=mn)?(i+1):((m+n-(i+1)<=mn)?(m+n-(i+1)):mn));
			res[i][s] = 0;
			adj[s].push_back(i);
			adj[i].push_back(s);
		}
		for (i=0; i<k; i++) {
			cin>>res[i+k][t];
			res[i+k][t] -= ((i+1<=mn)?(i+1):((m+n-(i+1)<=mn)?(m+n-(i+1)):mn));
			res[t][i+k] = 0;
			adj[i+k].push_back(t);
			adj[t].push_back(i+k);
		}
		for (i=0; i<n; i++) for (j=0; j<m; j++) {
			int a = i+j, b = k+(m-1)+i-j;
			adj[a].push_back(b);
			adj[b].push_back(a);
			res[a][b] = 99;
			res[b][a] = 0;
		}
		max_flow();
		cout<<"Case "<<it<<":\n";
		for (i=0; i<n; i++) {
			cout<<res[k+(m-1)+i][i]+1;
			for (j=1; j<m; j++) cout<<" "<<res[k+(m-1)+i-j][i+j]+1;
			cout<<"\n";
		}
	}
	
	return 0;
}
