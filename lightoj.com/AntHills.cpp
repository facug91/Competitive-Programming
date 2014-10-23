/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1063
        Name: Ant Hills
        Number: 1063
        Date: 17/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 131071
//#define MAXN 10000010

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, m, u, v, df_number[10005], low[10005], father[10005], ans;
vector<int> graph[10005];

void dfs (int idx) {
	bool art_point = false;
	for (int i=0; i<(int)graph[idx].size(); i++) {
		if (df_number[graph[idx][i]] == -1) {
			df_number[graph[idx][i]] = df_number[idx] + 1;
			low[graph[idx][i]] = df_number[idx] + 1;
			father[graph[idx][i]] = idx;
			dfs(graph[idx][i]);
			if (low[graph[idx][i]] >= df_number[idx]) art_point = true;
			low[idx] = min(low[graph[idx][i]], low[idx]);
		} else if (graph[idx][i] != father[idx]) {
			low[idx] = min(low[idx], df_number[graph[idx][i]]);
		}
	}
	if (art_point) ans++;
}
void dfs_main () {
	df_number[1] = 0;
	low[1] = 0;
	father[1] = 1;
	int cont = 0;
	for (int i=0; i<(int)graph[1].size(); i++) {
		if (df_number[graph[1][i]] == -1) {
			cont++;
			df_number[graph[1][i]] = 1;
			low[graph[1][i]] = 1;
			father[graph[1][i]] = 1;
			dfs(graph[1][i]);
		}
	}
	if (cont > 1) ans++;
}

int main() {
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>n>>m;
		for (i=1; i<=n; i++) {
			graph[i].clear();
			df_number[i] = -1;
		}
		for (i=0; i<m; i++) {
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		ans = 0;
		dfs_main();
		cout<<"Case "<<it<<": "<<ans<<endl;
	}
	
	
	
	
	
	
	
	
	
	return 0;
}
