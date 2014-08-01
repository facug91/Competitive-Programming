/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2782
	Name: Super Mario
	Number: 2782
	Date: 29/06/2014
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
#define _log2(x) log(x) * 1.44269504088896340736
//const long double PI = 2*acos(0);

#define INF 1000000000
//
using namespace std;

int n, ans, path_length[15][15], dist1[] = {0, 1, 0, -1}, dist2[] = {1, 0, -1, 0};
bool visited[15][15];
char board[15][15];
pair<int, int> mario;
queue<pair<int, int> > q;

bool check_pos (int x, int y) {
	return ((x >= 0) && (x < n) && (y >= 0) && (y < n));
}

int bfs () {
	int i, j;
	for (i=0; i<n; i++) {
		memset(visited[i], 0, sizeof visited[i]);
		for (j=0; j<n; j++)
			path_length[i][j] = INF;
	}
	visited[mario.first][mario.second] = true;
	path_length[mario.first][mario.second] = 0;
	q.push(make_pair(mario.first, mario.second));
	pair<int, int> act;
	int x, y, xx, yy, d;
	while (!q.empty()) {
		act = q.front();
		q.pop();
		x = act.first;
		y = act.second;
		for (d=0; d<4; d++) {
			xx = x+dist1[d];
			yy = y+dist2[d];
			if ((check_pos(xx, yy)) && (!visited[xx][yy]) && (board[xx][yy] != '*')) {
				if (board[xx][yy] == '#') return (path_length[x][y]+1);
				visited[xx][yy] = true;
				path_length[xx][yy] = path_length[x][y]+1;
				q.push(make_pair(xx, yy));
			}
		}
	}
	return 0;
}

int main () {
	
	int i, j;
	
	scanf("%d", &n);
	
	for (i=0; i<n; i++) {
		scanf("%s", board[i]);
		for (j=0; j<n; j++) {
			if (board[i][j] == 'm')
				mario = make_pair(i, j);
		}
	}
	
	ans = bfs();
	
	if (ans == 0) printf("-1\n");
	else printf("%d\n", ans);
	
	return 0;
}
