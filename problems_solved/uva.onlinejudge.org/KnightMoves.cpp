/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=380
	Name: Knight Moves
	Number: 439
	Date: 05/07/2014
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

using namespace std;

int graph[10][10], sssp[10][10], disti[] = {1, 2, 2, 1, -1, -2, -2, -1}, distj[] = {2, 1, -1, -2, -2, -1, 1, 2};
char a[5], b[5];
queue<pair<int, int> > q;
bool vis[10][10];

bool check_pos (int x, int y) {
	return ((x >= 0) && (x < 8) && (y >= 0) && (y < 8));
}

int bfs (int xk0, int yk0, int xk1, int yk1) {
	if ((xk0 == xk1) && (yk0 == yk1)) return 0;
	memset(vis, 0, sizeof vis);
	vis[xk0][yk0] = true;
	sssp[xk0][yk0] = 0;
	q.push(make_pair(xk0, yk0));
	pair<int, int> act;
	int x, y, w, z, d;
	while (!q.empty()) {
		act = q.front();
		q.pop();
		x = act.first; y = act.second;
		for (d=0; d<8; d++) {
			w = x+disti[d]; z = y+distj[d];
			if (check_pos(w, z) && !vis[w][z]) {
				if ((w == xk1) && (z == yk1)) return sssp[x][y]+1;
				vis[w][z] = true;
				sssp[w][z] = sssp[x][y]+1;
				q.push(make_pair(w, z));
			}
		}
	}
}

int main() {
	int i, j;
	while (scanf("%s %s", a, b) != EOF) {
		for (i=0; i<10; i++)
			for (j=0; j<10; j++)
				graph[i][j] = INF;
		printf("To get from %s to %s takes %d knight moves.\n", a, b, bfs(a[0]-'a', a[1]-'1', b[0]-'a', b[1]-'1'));
		while (!q.empty()) q.pop();
	}	
	
	return 0;
}
