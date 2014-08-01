/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1019
	Name: Brush (V)
	Number: 1019
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

int n, m, graph[105][105], u, v, w;

void floyd_warshall () {
	for (int k=0; k<n; k++)
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				if (graph[i][j] > graph[i][k]+graph[k][j])
					graph[i][j] = graph[i][k]+graph[k][j];
}

int main() {
	int t, i, j;
	
	scanf("%d", &t);
	for (int it=1; it<=t; it++) {
		scanf("%d %d", &n, &m);
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++)
				graph[i][j] = INF;
			graph[i][i] = 0;
		}
		for (i=0; i<m; i++) {
			scanf("%d %d %d", &u, &v, &w);
			u--; v--;
			if (graph[u][v] > w) {
				graph[u][v] = w;
				graph[v][u] = w;
			}
		}
		floyd_warshall();
		if (graph[0][n-1] == INF) printf("Case %d: Impossible\n", it);
		else printf("Case %d: %d\n", it, graph[0][n-1]);
	}
	
	return 0;
}
