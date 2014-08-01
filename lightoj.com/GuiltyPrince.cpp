/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1012
	Name: Guilty Prince
	Number: 1012
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

int w, h, ans, di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
char land[25][25];
ii prince;
queue<ii> q;
bool vis[25][25];

ii initial_position () {
	for (int i=0; i<h; i++)
		for (int j=0; j<w; j++)
			if (land[i][j] == '@')
				return make_pair(i, j);
}

bool check_pos (int x, int y) {return (x < h) && (x >= 0) && (y < w) && (y >= 0);}

void bfs () {
	memset(vis, 0, sizeof vis);
	q.push(prince);
	ans = 1;
	vis[prince.first][prince.second] = true;
	ii act;
	while (!q.empty()) {
		act = q.front();
		q.pop();
		int x = act.first;
		int y = act.second;
		for (int d=0; d<4; d++) {
			if (check_pos(x+di[d], y+dj[d]) && (land[x+di[d]][y+dj[d]] == '.') && !vis[x+di[d]][y+dj[d]]) {
				vis[x+di[d]][y+dj[d]] = true;
				q.push(make_pair(x+di[d], y+dj[d]));
				ans++;
			}
		}
	}
}

int main() {
	int t, i, j;
	
	scanf("%d", &t);
	for (int it=1; it<=t; it++) {
		scanf("%d %d", &w, &h);
		for (i=0; i<h; i++)
			scanf("%s", land[i]);
		prince = initial_position();
		bfs();
		printf("Case %d: %d\n", it, ans);
	}
	
	return 0;
}
