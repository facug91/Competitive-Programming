/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3018
        Name: Harrichu and the Maze
        Date: 26/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
string board[35];
bool vis[35][35];
ii s, t;

bool bfs () {
	memset(vis, 0, sizeof vis);
	queue<ii> q; q.push(s);
	vis[s.first][s.second] = true;
	ii u, v;
	while (q.size()) {
		u = q.front(); q.pop();
		for (int i=0; i<4; i++) {
			v.first = u.first + dx[i];
			v.second = u.second + dy[i];
			if ((board[v.first][v.second] == 'b' || board[v.first][v.second] == 'g' || board[v.first][v.second] == '.') && !vis[v.first][v.second]) {
				if (v == t) return true;
				vis[v.first][v.second] = true;
				q.push(v);
			}
		}
	}
	return false;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n>>m;
		for (i=0; i<n; i++) cin>>board[i];
		for (i=0; i<n; i++) for (j=0; j<m; j++) {
			if (board[i][j] == 'b') s.first = i, s.second = j;
			if (board[i][j] == 'g') t.first = i, t.second = j;
		}
		if (bfs()) cout<<"Good\n";
		else cout<<"Bad\n";
	}
	
	return 0;
}
