/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1033
        Name: The Problem with the Problem Setter
        Date: 18/02/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
#define find asjkldhakjsdbsakjdb
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, k, c, p, s, t, res[1050][1050], mf, level[1050];
vector<int> adj[1050];

bool bfs () {
	queue<int> q; q.push(s);
	memset(level, -1, sizeof level);
	level[s] = 0;
	int u, v, i;
	while (q.size()) {
		u = q.front(); q.pop();
		for (i=0; i<adj[u].size(); i++) {
			v = adj[u][i];
			if (level[v] == -1 && res[u][v] > 0) {
				level[v] = level[u] + 1;
				if (v == t) return true;
				q.push(v);
			}
		}
	}
	return false;
}

int dfs (int u, int min_edge) {
	if (u == t) return min_edge;
	int v, i, fsum = 0, faux;
	for (i=0; i<adj[u].size(); i++) {
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
	mf = 0;
	while (bfs()) mf += dfs(s, MAX_INT);
	return mf;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
    
    while (cin>>n>>m, n || m) {
		
		memset(res, 0, sizeof res);
		for (i=0; i<1050; i++) adj[i].clear();
		s = 0; t = 1;
		
		p = 0;
		for (i=2; i<n+2; i++) {
			cin>>c;
			p += c;
			res[s][i] = c;
			adj[s].push_back(i);
			adj[i].push_back(s);
		}
		
		for (i=n+2; i<m+n+2; i++) {
			res[i][t] = 1;
			adj[i].push_back(t);
			adj[t].push_back(i);
			cin>>k;
			for (j=0; j<k; j++) {
				cin>>c;
				res[c+1][i] = 1;
				adj[c+1].push_back(i);
				adj[i].push_back(c+1);
			}
		}
		
		max_flow();
		if (mf != p) cout<<"0"<<endl;
		else {
			cout<<"1"<<endl;
			bool first;
			for (i=2; i<n+2; i++) {
				first = true;
				for (j=0; j<adj[i].size(); j++) {
					if (res[i][adj[i][j]] == 0) {
						if (first) first = false;
						else cout<<" ";
						cout<<adj[i][j]-n-1;
					}
				}
				cout<<endl;
			}
		}
	}
    
	return 0;
}
