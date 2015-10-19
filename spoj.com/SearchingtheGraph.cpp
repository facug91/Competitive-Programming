/*
        By: facug91
        From: http://www.spoj.com/problems/TDBFS/
        Name: Searching the Graph
        Date: 25/11/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, m, u, v, s;
bool vis[1005];
vector<int> graph[1005];
queue<int> q;

void bfs (int idx) {
	vis[idx] = true;
	q.push(idx);
	int act, i;
	while(!q.empty()) {
		act = q.front();
		q.pop();
		for (i=0; i<(int)graph[act].size(); i++) {
			if (!vis[graph[act][i]]) {
				vis[graph[act][i]] = true;
				printf(" %d", graph[act][i]);
				q.push(graph[act][i]);
			}
		}
	}
}

void dfs (int idx) {
	vis[idx] = true;
	for (int i=0; i<(int)graph[idx].size(); i++) {
		if (!vis[graph[idx][i]]) {
			printf(" %d", graph[idx][i]);
			dfs(graph[idx][i]);
		}
	}
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	scanf("%d", &TC);
	for (int it=1; it<=TC; it++) {
		printf("graph %d\n", it);
		scanf("%d", &n);
		for (i=1; i<=n; i++)
			graph[i].clear();
		for (i=1; i<=n; i++) {
			scanf("%d %d", &u, &m);
			for (j=0; j<m; j++) {
				scanf("%d", &v);
				graph[u].push_back(v);
			}
		}
		
		while (scanf("%d %d", &v, &s), v || s) {
			printf("%d", v);
			memset(vis, 0, sizeof vis);
			if (s) bfs(v);
			else dfs(v);
			printf("\n");
		}
	}
	
	return 0;
}
