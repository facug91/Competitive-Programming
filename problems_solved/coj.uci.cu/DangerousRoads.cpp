/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2835
        Name: Dangerous Roads
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

int n, u, v;
map<int, int> graph[100005];
vector<ii> edges;

int dfs (int idx, int father) {
	int ans = 0;
	for (map<int, int>::iterator itr=graph[idx].begin(); itr!=graph[idx].end(); itr++) {
		if ((*itr).first != father) {
			if ((*itr).second == 0) {
				(*itr).second = dfs((*itr).first, idx);
			}
			ans += (*itr).second;
		}
	}
	return ans + 1;
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	scanf("%d", &n);
	for (i=1; i<n; i++) {
		scanf("%d %d", &u, &v);
		edges.push_back(ii(u, v));
		graph[u][v] = 0;
		graph[v][u] = 0;
	}
	for (i=1; i<=n; i++) {
		for (map<int, int>::iterator itr=graph[i].begin(); itr!=graph[i].end(); itr++) {
			if ((*itr).second == 0) {
				(*itr).second = dfs((*itr).first, i);
			}
		}
	}
	for (i=0; i<n-1; i++) {
		printf("%lld\n", ((ll)graph[edges[i].first][edges[i].second])*((ll)graph[edges[i].second][edges[i].first]));
	}
	
	return 0;
}
