/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=945
        Name: Bicoloring
        Number: 10004
        Date: 24/08/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN N

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, m, u, v, color[205], c[] = {0, 2, 1};
vector<int> graph[205];

bool bicolorable (int idx) {
	for (int i=0; i<(int)graph[idx].size(); i++) {
		if (color[graph[idx][i]]) {
			if (color[graph[idx][i]] == color[idx]) return false;
		} else {
			color[graph[idx][i]] = c[color[idx]];
			if (!bicolorable(graph[idx][i])) return false;
		}
	}
	return true;
}

int main () {
	ios_base::sync_with_stdio(0);
	int i, j;
	
	while (cin>>n, n) {
		cin>>m;
		for (i=0; i<n; i++)
			graph[i].clear();
		for (i=0; i<m; i++) {
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		memset(color, 0, sizeof color);
		color[0] = 1;
		if (bicolorable(0)) printf("BICOLORABLE.\n");
		else printf("NOT BICOLORABLE.\n");
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

