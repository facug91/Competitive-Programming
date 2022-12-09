/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=1522
        Name: Warriors of Narnia
        Date: 20/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
#define MP make_pair
#define F first
#define S second
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int h, w, mat[1005][1005], dis[2][1005][1005], dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, ans;
ii s[2];

void bfs (int idx) {
	int i, j;
	ii u, v;
	for (i=0; i<h; i++) for (j=0; j<w; j++) dis[idx][i][j] = INF;
	dis[idx][s[idx].F][s[idx].S] = 0;
	queue<ii> q; q.push(s[idx]);
	while (q.size()) {
		u = q.front(); q.pop();
		for (i=0; i<4; i++) {
			v.F = u.F + dx[i];
			v.S = u.S + dy[i];
			if (v.F >= 0 && v.F < h && v.S >= 0 && v.S < w && mat[v.F][v.S] != 1 && mat[v.F][v.S] != 3 && dis[idx][v.F][v.S] == INF) {
				dis[idx][v.F][v.S] = dis[idx][u.F][u.S] + 1;
				q.push(v);
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, j;
	
	cin>>w>>h;
	for (i=0; i<h; i++) for (j=0; j<w; j++) cin>>mat[i][j];
	for (i=0; i<h; i++) for (j=0; j<w; j++) if (mat[i][j] == 2 || mat[i][j] == 3) s[(mat[i][j] != 2)] = MP(i, j);
	bfs(0); bfs(1);
	ans = INT_MAX;
	for (i=0; i<h; i++) for (j=0; j<w; j++) if (mat[i][j] == 4) ans = min(ans, dis[0][i][j]+dis[1][i][j]);
	cout<<ans<<"\n";
	
	return 0;
}
