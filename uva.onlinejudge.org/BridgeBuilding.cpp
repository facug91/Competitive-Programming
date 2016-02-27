/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=917
        Name: Bridge Building
        Date: 25/02/2016
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

int r, c, b, s, side[2][1005], dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, dif[1005], DP[1005][1005];
string mat[1005];
bool vis[1005][1005];

void dfs (int i, int j, int idx) {
	vis[i][j] = true;
	if (idx == 0) side[0][j] = max(side[0][j], i);
	else 		  side[1][j] = min(side[1][j], i);
	for (int di=0; di<4; di++) {
		int x = i + dx[di];
		int y = j + dy[di];
		if (x >= 0 && y >= 0 && x < r && y < c && !vis[x][y] && mat[x][y] == '#') dfs(x, y, idx);
	}
}

int dp (int u, int k) {
	if (k == b) return 0;
	if (u >= c) return INF;
	if (DP[u][k] != -1) return DP[u][k];
	return DP[u][k] = min(dp(u+s+1, k+1) + dif[u], dp(u+1, k));
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	while (cin>>r>>c>>b>>s) {
		for (i=0; i<r; i++) cin>>mat[i];
		for (i=0; i<c; i++) {
			side[0][i] = -1;
			side[1][i] = 1005;
		}
		memset(vis, 0, sizeof vis);
		dfs(0, 0, 0);
		dfs(r-1, 0, 1);
		for (i=0; i<c; i++) dif[i] = side[1][i] - side[0][i] - 1;
		memset(DP, -1, sizeof DP);
		cout<<dp(0, 0)<<endl;
	}
	
	return 0;
}
