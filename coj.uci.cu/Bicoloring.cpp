/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3081
        Name: Bicoloring
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

int n, l, u, v, color[250];
vector<int> graph[250];

bool dfs (int idx) {
	int c = (color[idx] == 1) ? 2 : 1;
	for (int i=0; i<(int)graph[idx].size(); i++) {
		if (!color[graph[idx][i]]) {
			color[graph[idx][i]] = c;
			if (!dfs(graph[idx][i])) {
				return false;
			}
		} else if (color[graph[idx][i]] == color[idx]) {
			return false;
		}
	}
	return true;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>n, n) {
		for (i=0; i<n; i++) {
			graph[i].clear();
			color[i] = 0;
		}
		cin>>l;
		for (i=0; i<l; i++) {
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		color[0] = 1;
		if (dfs(0)) cout<<"BICOLORABLE."<<endl;
		else cout<<"NOT BICOLORABLE."<<endl;
	}
	
	return 0;
}
