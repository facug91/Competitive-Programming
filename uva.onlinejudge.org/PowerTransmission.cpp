/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1271
        Name: Power Transmission
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

int n, m, a, b, d, s, t, level[305];
ll c, res[305][305], mf;
vi adj[305];

bool bfs () {
	queue<int> q; q.push(s);
	memset(level, -1, sizeof level);
	level[s] = 0;
	int u, v, i;
	while (q.size()) {
		u = q.front(); q.pop();
		for (i=0; i<adj[u].size(); i++) {
			v = adj[u][i];
			if (level[v] == -1 && res[u][v] > 0ll) {
				level[v] = level[u] + 1;
				if (v == t) return true;
				q.push(v);
			}
		}
	}
	return false;
}

ll dfs (int u, ll min_edge) {
	if (u == t) return min_edge;
	int v, i;
	ll faux, fsum = 0ll;
	for (i=0; i<adj[u].size(); i++) {
		v = adj[u][i];
		if (level[v] == level[u] + 1 && res[u][v] > 0ll) {
			faux = dfs(v, min(min_edge, res[u][v]));
			if (faux) {
				fsum += faux;
				res[u][v] -= faux;
				res[v][u] += faux;
				min_edge -= faux;
				if (min_edge == 0ll) break;
			}
		}
	}
	return fsum;
}

ll max_flow () {
	mf = 0ll;
	while (bfs()) mf += dfs(s, MAX_LONG);
	return mf;
}

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j;
	
	while (cin>>n) {
		memset(res, 0, sizeof res);
		for (i=0; i<305; i++) adj[i].clear();
		s = 0; t = 1;
		
		for (i=1; i<=n; i++) {
			cin>>c;
			res[i*2][i*2+1] = c;
			adj[i*2].push_back(i*2+1);
			adj[i*2+1].push_back(i*2);
		}
		cin>>m;
		for (i=0; i<m; i++) {
			cin>>a>>b>>c;
			if (res[a*2+1][b*2] == 0ll) {
				adj[a*2+1].push_back(b*2);
				adj[b*2].push_back(a*2+1);
			}
			res[a*2+1][b*2] += c;
		}
		cin>>b>>d;
		for (i=0; i<b; i++) {
			cin>>a;
			res[s][a*2] = MAX_LONG;
			adj[s].push_back(a*2);
			adj[a*2].push_back(s);
		}
		for (i=0; i<d; i++) {
			cin>>a;
			res[a*2+1][t] = MAX_LONG;
			adj[a*2+1].push_back(t);
			adj[t].push_back(a*2+1);
		}
		cout<<max_flow()<<endl;
	}
	
	return 0;
}
