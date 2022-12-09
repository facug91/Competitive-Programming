/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1002
	Name: Country Roads
	Number: 1002
	Date: 22/07/2014
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

int n, m, s, u, v, w, p[501], rank[501], ans;
vector<pair<int, pair<int, int> > > edges;
vector<pair<int, int> > graph[501];

int find_set (int i) {return (p[i] == i) ? i : (p[i] = find_set(p[i]));}

void union_set (int i, int j, int w) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		graph[i].push_back(make_pair(j, w));
		graph[j].push_back(make_pair(i, w));
		if (rank[x] > rank[y]) {
			p[y] = x;
		} else {
			p[x] = y;
			if (rank[y] == rank[x]) rank[y]++;
		}
	}
}

bool found, used[501];
int dfs (int x, int w) {
	if (x == s) {
		found = true;
		return w;
	}
	int ans = -1;
	for (int i=0; (i<graph[x].size()) && (!found); i++) {
		if (!used[graph[x][i].first]) {
			used[graph[x][i].first] = true;
			ans = max(dfs(graph[x][i].first, graph[x][i].second), w);
		}
	}
	return ans;
}

int main() {
	int t, i, j;
	
	scanf("%d", &t);
	for (int it=1; it<=t; it++) {
		scanf("%d %d", &n, &m);
		for (i=0; i<n; i++) {
			p[i] = i;
			rank[i] = 0;
			graph[i].clear();
		}
		edges.clear();
		for (i=0; i<m; i++) {
			scanf("%d %d %d", &u, &v, &w);
			edges.push_back(make_pair(w, make_pair(u, v)));
		}
		sort(edges.begin(), edges.end());
		for (i=0; i<m; i++)
			union_set(edges[i].second.first, edges[i].second.second, edges[i].first);
		scanf("%d", &s);
		printf("Case %d:\n", it);
		for (i=0; i<n; i++) {
			if (i == s) printf("0\n");
			else {
				found = false;
				memset(used, 0, sizeof used);
				used[i] = true;
				ans = dfs(i, -1);
				if (found) printf("%d\n", ans);
				else printf("Impossible\n");
			}
		}
	}
	
	return 0;
} 
