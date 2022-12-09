/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1986
        Name: My T-shirt suits me
        Date: 10/01/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
#define MAXN 105

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int n, m, res[MAXN][MAXN], mf, f, s, t, p[MAXN];
string s1, s2;
vector<int> graph[MAXN];
map<string, int> size;

void augment (int v, int min_edge) {
	if (v == s) {
		f = min_edge;
		return;
	} else if (p[v] != -1) {
		augment(p[v], min(min_edge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}

int edmonds_karp () {
	int i, j, u, v;
	bitset<MAXN> vis;
	mf = 0;
	while (true) {
		f = 0;
		memset(p, -1, sizeof p);
		vis.reset();
		vis[s] = true;
		queue<int> q; q.push(s);
		while (!q.empty()) {
			u = q.front(); q.pop();
			if (u == t) break;
			for (j=0; j<(int)graph[u].size(); j++) {
				v = graph[u][j];
				if (res[u][v] > 0 && !vis[v]) {
					vis[v] = true;
					q.push(v);
					p[v] = u;
				}
			}
		}
		augment(t, INF);
		if (f == 0) break;
		mf += f;
	}
	return mf;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j, k;
	
	size["XS"] = 2;
	size["S"] = 3;
	size["M"] = 4;
	size["L"] = 5;
	size["XL"] = 6;
	size["XXL"] = 7;
	for (i=2; i<8; i++)
		graph[i].push_back(1);
	s = 0; t = 1;
	
	cin>>TC;
	while (TC--) {
		memset(res, 0, sizeof res);
		cin>>n>>m;
		for (i=2; i<8; i++)
			res[i][1] = n/6;
		graph[0].clear();
		for (i=8; i<m+8; i++) {
			graph[0].push_back(i);
			res[0][i] = 1;
			graph[i].clear();
		}
		for (i=8; i<m+8; i++) {
			cin>>s1>>s2;
			if (s1 != s2) {
				graph[i].push_back(size[s1]);
				graph[i].push_back(size[s2]);
				graph[size[s1]].push_back(i);
				graph[size[s2]].push_back(i);
				res[i][size[s1]] = 1;
				res[i][size[s2]] = 1;
			} else {
				graph[i].push_back(size[s1]);
				graph[size[s1]].push_back(i);
				res[i][size[s1]] = 2;
			}
		}
		if (edmonds_karp() == m) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}
