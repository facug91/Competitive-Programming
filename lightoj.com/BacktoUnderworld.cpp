/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1009
	Name: Back to Underworld
	Number: 1009
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

int n, u, v, ans;
vector<int> graph[20005];
bool vis[20005];
ii cant;

ii dfs (int idx, int color) {
	ii act, ans(0, 0);
	if (color) ans.first = 1;
	else ans.second = 1;
	for (int i=0; i<(int)graph[idx].size(); i++) {
		if (!vis[graph[idx][i]]) {
			vis[graph[idx][i]] = true;
			act = dfs(graph[idx][i], (color+1)%2);
			ans.first += act.first;
			ans.second += act.second;
		}
	}
	return ans;
}

int main() {
	int t, i, j;
	
	scanf("%d", &t);
	for (int it=1; it<=t; it++) {
		for (i=0; i<20005; i++)
			graph[i].clear();
		scanf("%d", &n);
		for (i=0; i<n; i++) {
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		memset(vis, 0, sizeof vis);
		ans = 0;
		for (i=0; i<20005; i++)
			if ((graph[i].size() != 0) && (!vis[i])) {
				vis[i] = true;
				cant = dfs(i, 0);
				ans += max(cant.first, cant.second);
			}
		
		printf("Case %d: %d\n", it, ans);
	}
	
	
	
	
	
	return 0;
}
