/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=1982
        Name: Cow Beauty Pageant I
        Date: 27/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, m, dis[55][55], di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
string grid[55];
queue<ii> q1, q2;
ii start;

ii find_start () {
	int i, j;
	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			if (grid[i][j] == 'X')
				return ii(i, j);
}
bool check_pos (int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}
void bfs1 () {
	q1.push(start);
	q2.push(start);
	dis[start.first][start.second] = 0;
	grid[start.first][start.second] = '.';
	ii act;
	while (!q1.empty()) {
		act = q1.front();
		int x = act.first;
		int y = act.second;
		q1.pop();
		for (int d=0; d<4; d++) {
			int w = x + di[d];
			int z = y + dj[d];
			if (check_pos(w, z) && grid[w][z] == 'X') {
				q1.push(ii(w, z));
				q2.push(ii(w, z));
				dis[w][z] = 0;
				grid[w][z] = '.';
			}
		}
	}
}
int bfs2 () {
	ii act;
	while (!q2.empty()) {
		act = q2.front();
		int x = act.first;
		int y = act.second;
		q2.pop();
		for (int d=0; d<4; d++) {
			int w = x + di[d];
			int z = y + dj[d];
			if (check_pos(w, z)) {
				if (grid[w][z] == 'X') {
					return dis[x][y];
				} else {
					if (dis[w][z] == INF) {
						dis[w][z] = dis[x][y] + 1;
						q2.push(ii(w, z));
					}
				}
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>n>>m;
	for (i=0; i<n; i++)
		cin>>grid[i];
	start = find_start();
	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			dis[i][j] = INF;
	bfs1();
	cout<<bfs2()<<endl;
	
	
	
	
	
	
	
	return 0;
}
