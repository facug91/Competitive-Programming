/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1094
	Name: Farthest Nodes in a Tree
	Number: 1094
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

int n, u, v, w, dis[30005];
vector<ii> tree[30005];
bool vis[30005];

void dfs (int idx) {
	for (int i=0; i<tree[idx].size(); i++) {
		if (!vis[tree[idx][i].first]) {
			vis[tree[idx][i].first] = true;
			dis[tree[idx][i].first] = dis[idx]+tree[idx][i].second;
			dfs(tree[idx][i].first);
		}
	}
}

int main() {
	int t, i, j;
	
	scanf("%d", &t);
	for (int it=1; it<=t; it++) {
		scanf("%d", &n);
		for (i=0; i<n; i++)
			tree[i].clear();
		for (i=0; i<n-1; i++) {
			scanf("%d %d %d", &u, &v, &w);
			tree[u].push_back(make_pair(v, w));
			tree[v].push_back(make_pair(u, w));
		}
		vis[0] = true; dis[0] = 0;
		for (i=1; i<n; i++)
			vis[i] = false;
		dfs(0);
		int mx = -1, idx;
		for (i=1; i<n; i++)
			if (dis[i] > mx) {
				mx = dis[i];
				idx = i;
			}
		for (i=0; i<n; i++)
			vis[i] = false;
		vis[idx] = true; dis[idx] = 0;
		dfs(idx);
		mx = -1;
		for (i=0; i<n; i++)
			if (dis[i] > mx)
				mx = dis[i];
		printf("Case %d: %d\n", it, mx);
	}
	
	return 0;
}
