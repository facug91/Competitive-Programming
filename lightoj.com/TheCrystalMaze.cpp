/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1337
        Name: The Crystal Maze
        Date: 08/01/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, m, q, DP[505][505], c, x, y, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
bool vis[505][505];
string s[505];

bool check_pos (int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

int dfs (int x, int y) {
	vis[x][y] = true;
	int ans = (s[x][y] == 'C');
	for (int d=0; d<4; d++)
		if (check_pos(x+dx[d], y+dy[d]) && !vis[x+dx[d]][y+dy[d]] && s[x+dx[d]][y+dy[d]] != '#')
			ans += dfs(x+dx[d], y+dy[d]);
	return ans;
}

void dp (int x, int y, int c) {
	DP[x][y] = c;
	for (int d=0; d<4; d++)
		if (check_pos(x+dx[d], y+dy[d]) && s[x+dx[d]][y+dy[d]] != '#' && DP[x+dx[d]][y+dy[d]] == -1)
			dp(x+dx[d], y+dy[d], c);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j, k;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>n>>m>>q;
		for (i=0; i<n; i++)
			cin>>s[i];
		memset(DP, -1, sizeof DP);
		memset(vis, 0, sizeof vis);
		for (i=0; i<n; i++) {
			for (j=0; j<m; j++) {
				if (!vis[i][j] && s[i][j] != '#') {
					c = dfs(i, j);
					dp(i, j, c);
				}
			}
		}
		cout<<"Case "<<it<<":"<<endl;
		for (i=0; i<q; i++) {
			cin>>x>>y; x--; y--;
			cout<<DP[x][y]<<endl;
		}
	}
	
	return 0;
}
