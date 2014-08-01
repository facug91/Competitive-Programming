/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1111
	Name: Best Picnic Ever
	Number: 1111
	Date: 23/07/2014
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iterator>
#include <utility>
#include <list>
#include <stack>
#include <iomanip>
#include <bitset>

#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
//const long double PI = 2*acos(0);

#define INF 1000000000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int k, n, m, u, v, live[105], ans;
vector<int> graph[1005];
bool reachable[1005], vis[1005];

void dfs (int idx) {
	for (int i=0; i<graph[idx].size(); i++)
		if (!vis[graph[idx][i]]) {
			vis[graph[idx][i]] = true;
			dfs(graph[idx][i]);
		}
}

int main() {
	int t, i, j;
	
	scanf("%d", &t);
	for (int it=1; it<=t; it++) {
		scanf("%d %d %d", &k, &n, &m);
		for (i=1; i<=n; i++)
			graph[i].clear();
		for (i=0; i<k; i++)
			scanf("%d", live+i);
		for (i=0; i<m; i++) {
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
		}
		for (i=1; i<=n; i++)
			reachable[i] = true;
		for (i=0; i<k; i++) {
			for (j=1; j<=n; j++)
				vis[j] = false;
			vis[live[i]] = true;
			dfs(live[i]);
			for (j=1; j<=n; j++)
				reachable[j] &= vis[j];
		}
		ans = 0;
		for (i=1; i<=n; i++)
			ans += reachable[i];
		printf("Case %d: %d\n", it, ans);
	}
	
	return 0;
}
