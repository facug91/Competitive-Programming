/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1049
	Name: One Way Roads
	Number: 1049
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

int n, a, b, c;
vector<ii> graph[101];
bool vis[101];

int dfs_main () {
	int act, sum[2], back;
	for (int i=0; i<2; i++) {
		memset(vis, 0, sizeof vis);
		act = graph[1][i].first, sum[i] = graph[1][i].second;
		vis[1] = vis[act] = true;
		back = graph[1][(i+1)%2].first;
		while (act != back) {
			if (!vis[graph[act][0].first]) {
				vis[graph[act][0].first] = true;
				sum[i] += graph[act][0].second;
				act = graph[act][0].first;
			} else {
				vis[graph[act][1].first] = true;
				sum[i] += graph[act][1].second;
				act = graph[act][1].first;
			}
		}
		if (graph[act][0].first == 1) sum[i] += graph[act][0].second;
		else sum[i] += graph[act][1].second;
	}
	
	return min(sum[0], sum[1]);
}

int main() {
	int t, i, j;
	
	scanf("%d", &t);
	for (int it=1; it<=t; it++) {
		scanf("%d", &n);
		for (i=1; i<=n; i++)
			graph[i].clear();
		for (i=0; i<n; i++) {
			scanf("%d %d %d", &a, &b, &c);
			graph[a].push_back(make_pair(b, 0));
			graph[b].push_back(make_pair(a, c));
		}
		printf("Case %d: %d\n", it, dfs_main());
	}
	
	return 0;
}
