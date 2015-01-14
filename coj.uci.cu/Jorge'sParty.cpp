/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2927
        Name: Jorge's Party
        Date: 26/12/2014
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

int n, m, u, v, color[1005];
vector<int> graph[1005];

bool dfs (int idx) {
	int next = (color[idx] == 1) ? 2 : 1;
	for (int i=0; i<(int)graph[idx].size(); i++) {
		if (color[graph[idx][i]] == 0) {
			color[graph[idx][i]] = next;
			if (!dfs(graph[idx][i])) return false;
		} else if (color[graph[idx][i]] == color[idx]) {
			return false;
		}
	}
	return true;
}

bool is_bicoloring () {
	memset(color, 0, sizeof color);
	for (int i=0; i<n; i++) {
		if (color[i] == 0) {
			color[i] = 1;
			if (!dfs(i)) return false;
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
	if (is_bicoloring()) {
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
	
	return 0;
}
