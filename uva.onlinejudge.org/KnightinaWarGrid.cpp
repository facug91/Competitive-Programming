/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3057
        Name: Knight in a War Grid
        Number: 11906
        Date: 01/09/2014
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
//#define MAXN 6005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int r, c, n, m, w, x, y, square[105][105], ans[2];
bool water[105][105], vis[105][105];
vector<ii> move;
queue<ii> q;

bool check_pos (int x, int y) {
	return !water[x][y] && (x >= 0) && (x < r) && (y >= 0) && (y < c); }

void bfs () {
	vis[0][0] = true;
	q.push(ii(0, 0));
	ii act; int x, y, jumps = (int)move.size();
	while (!q.empty()) {
		act = q.front();
		q.pop();
		for (int i=0; i<jumps; i++) {
			x = act.first+move[i].first;
			y = act.second+move[i].second;
			if (check_pos(x, y)) {
				square[act.first][act.second]++;
				if (!vis[x][y]) {
					q.push(ii(x, y));
					vis[x][y] = true;
				}
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>r>>c>>n>>m;
		if (n > m) swap(n, m);
		move.clear();
		if (m != 0) {
			if (n == m) {
				move.push_back(ii(n, n));
				move.push_back(ii(-n, n));
				move.push_back(ii(n, -n));
				move.push_back(ii(-n, -n));
			} else if (n == 0) {
				move.push_back(ii(0, m));
				move.push_back(ii(0, -m));
				move.push_back(ii(m, 0));
				move.push_back(ii(-m, 0));
			} else {
				move.push_back(ii(n, m));
				move.push_back(ii(n, -m));
				move.push_back(ii(-n, m));
				move.push_back(ii(-n, -m));
				move.push_back(ii(m, n));
				move.push_back(ii(m, -n));
				move.push_back(ii(-m, n));
				move.push_back(ii(-m, -n));
			}
		}
		memset(square, 0, sizeof square);
		memset(water, 0, sizeof water);
		memset(vis, 0, sizeof vis);
		cin>>w;
		while (w--) {
			cin>>x>>y;
			water[x][y] = true;
		}
		if (m == 0) {
			ans[0] = 1;
			ans[1] = 0;
		} else {
			bfs();
			ans[0] = ans[1] = 0;
			for (i=0; i<r; i++)
				for (j=0; j<c; j++)
					if (square[i][j]) ans[square[i][j]%2]++;
			if (square[0][0] == 0) ans[0] = 1;
		}
		cout<<"Case "<<it<<": "<<ans[0]<<" "<<ans[1]<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

