/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2724
        Name: Avoid the Lakes
        Number: 2724
        Date: 15/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007
//#define MAXN 3000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, m, k, x, y, ans, di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
char grid[105][105];
queue<ii> q;

bool check_pos (int x, int y) {
	return (x >= 1) && (x <= n) && (y >= 1) && (y <= m);
}
void bfs (int x, int y) {
	q.push(ii(x, y));
	grid[x][y] = '.';
	int cont = 0;
	ii act;
	while (!q.empty()) {
		act = q.front();
		q.pop();
		cont++;
		int x = act.first;
		int y = act.second;
		for (int d=0; d<4; d++) {
			int w = x + di[d];
			int z = y + dj[d];
			if (check_pos(w, z) && grid[w][z] == '#') {
				grid[w][z] = '.';
				q.push(ii(w, z));
			}
		}
	}
	if (cont > ans) ans = cont;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>n>>m>>k;
	memset(grid, '.', sizeof grid);
	for (i=0; i<k; i++) {
		cin>>x>>y;
		grid[x][y] = '#';
	}
	for (i=1; i<=n; i++) {
		for (j=1; j<=m; j++) {
			if (grid[i][j] == '#') {
				bfs(i, j);
			}
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
