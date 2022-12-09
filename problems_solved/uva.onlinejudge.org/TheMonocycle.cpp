/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=988
        Name: The Monocycle
        Date: 25/04/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, dis[25][25][5][4], ans, dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
bool vis[25][25][5][4], reachable;
string mat[30];
ii s, t;

void bfs () {
	int i, j, k, l, x, y, w, z, d, c0, c1;
	for (i=0; i<n; i++) for (j=0; j<m; j++) for (k=0; k<5; k++) for (l=0; l<4; l++) dis[i][j][k][l] = INF;
	memset(vis, 0, sizeof vis);
	dis[s.first][s.second][0][0] = 0;
	vis[s.first][s.second][0][0] = true;
	queue<iiii> q; q.push(iiii(ii(s.first, s.second), ii(0, 0)));
	iiii act;
	while (q.size()) {
		act = q.front(); q.pop();
		x = act.first.first;
		y = act.first.second;
		c0 = act.second.first;
		d = act.second.second;
		if (!vis[x][y][c0][(d+1)%4]) {
			vis[x][y][c0][(d+1)%4] = true;
			dis[x][y][c0][(d+1)%4] = dis[x][y][c0][d] + 1;
			q.push(iiii(ii(x, y), ii(c0, (d+1)%4)));
		}
		if (!vis[x][y][c0][(4+d-1)%4]) {
			vis[x][y][c0][(4+d-1)%4] = true;
			dis[x][y][c0][(4+d-1)%4] = dis[x][y][c0][d] + 1;
			q.push(iiii(ii(x, y), ii(c0, (4+d-1)%4)));
		}
		w = x + dx[d];
		z = y + dy[d];
		c1 = (c0 + 1) % 5;
		if (w >= 0 && w < n && z >= 0 && z < m && mat[w][z] != '#' && !vis[w][z][c1][d]) {
			vis[w][z][c1][d] = true;
			dis[w][z][c1][d] = dis[x][y][c0][d] + 1;
			q.push(iiii(ii(w, z), ii(c1, d)));
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	while (cin>>n>>m, n || m) {
		if (tc != 1) cout<<"\n";
		for (i=0; i<n; i++) cin>>mat[i];
		for (i=0; i<n; i++) for (j=0; j<m; j++) {
			if (mat[i][j] == 'S') s = ii(i, j);
			else if (mat[i][j] == 'T') t = ii(i, j);
		}
		bfs();
		reachable = false; ans = INT_MAX;
		for (i=0; i<4; i++) if (vis[t.first][t.second][0][i]) {
			reachable = true;
			ans = min(ans, dis[t.first][t.second][0][i]);
		}
		cout<<"Case #"<<tc++<<"\n";
		if (reachable) cout<<"minimum time = "<<ans<<" sec\n";
		else cout<<"destination not reachable\n";
	}
	
	return 0;
}
