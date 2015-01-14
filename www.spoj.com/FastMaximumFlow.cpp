/*
        By: facug91
        From: http://www.spoj.com/problems/FASTFLOW/
        Name: Fast Maximum Flow
        Date: 13/01/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 105

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m, a, b, c, s, t, level[5005];
ll mf, res[5005][5005];
vector<int> ady[5005];

bool bfs () {
	queue<int> q; q.push(s);
	memset(level, -1, sizeof level);
	level[s] = 0;
	int u, v;
	while (!q.empty()) {
		u = q.front(); q.pop();
		for (int i=0; i<(int)ady[u].size(); i++) {
			v = ady[u][i];
			if (level[v] == -1 && res[u][v] > 0ll) {
				level[v] = level[u] + 1;
				q.push(v);
				if (v == t) return true;
			}
		}
	}
	return false;
}

ll dfs (int u, ll min_edge) {
	if (u == t) return min_edge;
	int v; ll faux, fsum = 0;
	for (int i=0; i<(int)ady[u].size(); i++) {
		v = ady[u][i];
		if (res[u][v] > 0ll && level[v] == level[u] + 1) {
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

ll max_flow () {
	mf = 0ll;
	while (bfs()) mf += (ll)dfs(s, MAX_INT);
	return mf;
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j, k, im, ic, ip;
	
	scanf("%d %d", &n, &m);
	s = 1; t = n;
	for (i=0; i<m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a != b) {
			if (res[a][b] == 0ll) {
				ady[a].push_back(b);
				ady[b].push_back(a);
			}
			res[a][b] += (ll)c;
			res[b][a] += (ll)c;
		}
	}
	printf("%lld\n", max_flow());
	
	return 0;
}
