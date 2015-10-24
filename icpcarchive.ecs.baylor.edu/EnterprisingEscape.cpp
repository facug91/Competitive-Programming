/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=622&page=show_problem&problem=4527
        Name: Enterprising Escape
        Date: 18/08/2015
*/

#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef pair<int, int> ii;

int k, w, h, clas[300], dis[1005][1005], dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
bool vis[1005][1005];
char c;
string mat[1005];
priority_queue<pair<int, ii>, vector<pair<int, ii> >, greater<pair<int, ii> > > pq;

int dijkstra () {
	int i, j, x, y;
	for (i=0; i<h; i++) for (j=0; j<w; j++) {
		dis[i][j] = INF;
		vis[i][j] = false;
	}
	ii ori, u, v;
	for (i=0; i<h; i++) for (j=0; j<w; j++) if (mat[i][j] == 'E') ori = ii(i, j);
	dis[ori.first][ori.second] = 0;
	pair<int, ii> act;
	pq.push(make_pair(0, ori));
	while (pq.size()) {
		act = pq.top(); pq.pop();
		u = act.second;
		if (vis[u.first][u.second]) continue;
		vis[u.first][u.second] = true;
		for (int d=0; d<4; d++) {
			v = ii(u.first+dx[d], u.second+dy[d]);
			if (v.first >= 0 && v.first < h && v.second >= 0 && v.second < w && dis[v.first][v.second] > dis[u.first][u.second]+clas[mat[v.first][v.second]]) {
				dis[v.first][v.second] = dis[u.first][u.second]+clas[mat[v.first][v.second]];
				if (v.first > 0 && v.first < h-1 && v.second > 0 && v.second < w-1) pq.push(make_pair(dis[v.first][v.second], v));
			}
		}
	}
	int ans = INT_MAX;
	for (i=0; i<h; i++) ans = min(ans, min(dis[i][0], dis[i][w-1]));
	for (i=0; i<w; i++) ans = min(ans, min(dis[0][i], dis[h-1][i]));
	return ans;
}

int main(){
	int tc, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>k>>w>>h;
		for (i=0; i<k; i++) {
			cin>>c;
			cin>>clas[c];
		}
		clas['E'] = INF;
		for (i=0; i<h; i++) cin>>mat[i];
		cout<<dijkstra()<<endl;
	}
	
	
}

