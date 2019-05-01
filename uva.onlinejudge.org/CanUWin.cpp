/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2400
        Name: Can U Win?
        Date: 26/02/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 10005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, m, DP[9][1<<9], dis[9][9], dis2[8][8], limit, dx[] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
string board[8];
ii point[9];
bool vis[8][8];
queue<ii> q;

void bfs (int origin) {
	memset(vis, 0, sizeof vis);
	int i, j, x, y, w, z;
	ii curr;
	q.push(point[origin]);
	vis[point[origin].F][point[origin].S] = true;
	dis2[point[origin].F][point[origin].S] = 0;
	while (q.size()) {
		curr = q.front(); q.pop();
		x = curr.F;
		y = curr.S;
		if (board[x][y] >= '0' && board[x][y] <= '9') dis[origin][board[x][y]-'0'] = dis2[x][y];
		for (int di=0; di<8; di++) {
			w = x + dx[di];
			z = y + dy[di];
			if (w >= 0 && w < 8 && z >= 0 && z < 8 && !vis[w][z] && ((board[w][z] >= '0' && board[w][z] <= '9') || board[w][z] == '.')) {
				dis2[w][z] = dis2[x][y] + 1;
				vis[w][z] = true;
				q.push(ii(w, z));
			}
		}
	}
}

int dp (int u, int bm) {
	if (bm == limit) return 0;
	if (DP[u][bm] != -1) return DP[u][bm];
	int ans = INT_MAX;
	for (int v=0; v<n; v++) if ((bm & (1<<v)) == 0) ans = min(ans, dp(v, bm|(1<<v)) + dis[u][v]);
	return DP[u][bm] = ans;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>m;
		for (i=0; i<8; i++) cin>>board[i];
		n = 1;
		for (i=0; i<8; i++) for (j=0; j<8; j++) {
			if (board[i][j] == 'k') {
				board[i][j] = '0';
				point[0] = ii(i, j);
			} else if (board[i][j] == 'P') {
				board[i][j] = '0'+n;
				point[n++] = ii(i, j);
			}
		}
		for (i=0; i<n; i++) bfs(i);
		memset(DP, -1, sizeof DP);
		limit = (1 << n) - 1;
		if (dp(0, 1) <= m) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
	return 0;
}
