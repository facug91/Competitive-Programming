/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2559
        Name: Treasure Island
        Date: 09/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int r, c, island[505][505], dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, dis[505][505];
bool vis[505][505];

bool bfs (int t) {
	//DEBUG(t);
	if (island[0][0] <= t) return false;
	memset(vis, 0, sizeof vis);
	memset(dis, 0, sizeof dis);
	dis[0][0] = t; vis[0][0] = true;
	queue<ii> q; q.push(ii(0, 0));
	ii u, v; int i, j;
	while (q.size()) {
		u = q.front(); q.pop();
		for (i=0; i<4; i++) {
			v.first = u.first + dx[i];
			v.second = u.second + dy[i];
			if (v.first >= 0 && v.first < r && v.second >= 0 && v.second < c && !vis[v.first][v.second] && island[v.first][v.second] > dis[u.first][u.second] + 1) {
				vis[v.first][v.second] = true;
				dis[v.first][v.second] = dis[u.first][u.second] + 1;
				//if (v.first == r-1 && v.second == c-1) DEBUG(island[v.first][v.second]), DEBUG(dis[u.first][u.second]);
				if (v.first == r-1 && v.second == c-1) return true;
				q.push(ii(v.first, v.second));
			}
			/*
			cerr<<endl;
			for (int a=0; a<r; a++) {
				for (int b=0; b<c; b++) cerr<<dis[a][b]<<" ";
				cerr<<endl;
			}
			cerr<<endl;
			*/
		}
	}
	return false;
}

int binary_search () {
	if (!bfs(0)) return -1;
	int lo = 0, hi = 1000005, mid;
	for (int i=0; i<25; i++) {
		mid = (lo + hi) / 2;
		if (bfs(mid)) lo = mid;
		else hi = mid-1;
	}
	for (int i=hi; i>=lo; i--) if (bfs(i)) return i;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i, j;
	
	cin>>r>>c;
	for (i=0; i<r; i++) for (j=0; j<c; j++) cin>>island[i][j];
	cout<<binary_search()<<"\n";
	
	return 0;
}
