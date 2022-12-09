/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1238
	Name: Power Puff Girls
	Number: 1238
	Date: 24/07/2014
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

int n, m, dis[25][25], ans, act, di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
char graph[25][25];
ii girl[3], home;
bool vis[25][25];

int bfs (ii g) {
	int i, j, x, y, d, xd, yd;
	queue<ii> q;
	q.push(g);
	ii act;
	memset(vis, 0, sizeof vis);
	vis[g.first][g.second] = true;
	dis[g.first][g.second] = 0;
	while (!q.empty()) {
		act = q.front();
		q.pop();
		x = act.first;
		y = act.second;
		for (d=0; d<4; d++) {
			xd = x+di[d];
			yd = y+dj[d];
			if ((xd == home.first) && (yd == home.second))
				return (dis[x][y]+1);
			if ((graph[xd][yd] != 'm') && (graph[xd][yd] != '#') && (!vis[xd][yd])) {
				vis[xd][yd] = true;
				dis[xd][yd] = dis[x][y]+1;
				q.push(make_pair(xd, yd));
			}
		}
	}
}

int main() {
	int t, i, j;
	
	scanf("%d", &t);
	for (int it=1; it<=t; it++) {
		scanf("%d %d", &n, &m);
		for (i=0; i<n; i++)
			scanf("%s", graph[i]);
		for (i=0; i<n; i++)
			for (j=0; j<m; j++)
				if ((graph[i][j] >= 'a') && ('c' >= graph[i][j])) {
					girl[graph[i][j]-'a'].first = i;
					girl[graph[i][j]-'a'].second = j;
				} else if (graph[i][j] == 'h') {
					home.first = i;
					home.second = j;
				}
		ans = -1;
		for (i=0; i<3; i++) {
			act = bfs(girl[i]);
			if (act > ans) ans = act;
		}
		printf("Case %d: %d\n", it, ans);
	}
	
	return 0;
}
