/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3005
        Name: Decorating the Pastures
        Date: 27/12/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, m, u, v, color[50005], op[3];
vector<int> graph[50005];

bool dfs (int idx) {
	int c = (color[idx] == 1) ? 2 : 1;
	for (int i=0; i<(int)graph[idx].size(); i++) {
		if (!color[graph[idx][i]]) {
			op[c]++;
			color[graph[idx][i]] = c;
			if (!dfs(graph[idx][i]))
				return false;
		} else if (color[graph[idx][i]] == color[idx]) {
			return false;
		}
	}
	return true;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>n>>m;
	for (i=0; i<m; i++) {
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	memset(color, 0, sizeof color);
	int ans = 0; bool is_bipartite = true;
	for (i=1; i<=n && is_bipartite; i++) {
		if (!color[i]) {
			color[i] = 1;
			op[1] = 1;
			op[2] = 0;
			is_bipartite = (is_bipartite && dfs(i));
			ans += max(op[1], op[2]);
		}
	}
	if (is_bipartite) {
		cout<<ans<<endl;
	} else {
		cout<<"-1"<<endl;
	}
	
	return 0;
}
