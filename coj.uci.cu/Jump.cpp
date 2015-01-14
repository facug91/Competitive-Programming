/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2215
        Name: Jump
        Date: 19/10/2014
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
//#define MAXN 3000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, grid[1005][1005], di[] = {0, 0, 2, 3, 0, 0, -2, -3}, dj[] = {2, 3, 0, 0, -2, -3, 0, 0}, ans;

bool check_pos (int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}
bool bfs () {
	memset(grid, -1, sizeof grid);
	grid[0][0] = 0;
	queue<ii> q;
	q.push(ii(0, 0));
	int count = 1, limit = n*n;
	ii act;
	while ((!q.empty()) && (count != limit)) {
		act = q.front();
		q.pop();
		int x = act.first;
		int y = act.second;
		for (int d=0; d<8; d++) {
			int w = x + di[d];
			int z = y + dj[d];
			if (check_pos(w, z) && grid[w][z] == -1) {
				count++;
				grid[w][z] = grid[x][y] + 1;
				if (grid[w][z] > ans) ans = grid[w][z];
				q.push(ii(w, z));
			}
		}
	}
	return (count == limit);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n;
		if (bfs()) {
			cout<<ans<<endl;
		} else {
			cout<<"-1"<<endl;
		}
	}
	
	return 0;
}
