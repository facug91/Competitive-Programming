/*
        By: facug91
        From: http://acm.tju.edu.cn/toj/showp1343.html
        Name: Mondriaan's Dream
        Date: 15/01/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
typedef vector<int> vi;
typedef vector<ii> vii;

int h, w, limitw, board[12];
ll DP[11][1<<11];

ll dfs1 (int idx);
ll dfs2 (int idx);

ll dfs1 (int idx) {
	if (board[idx] == limitw) return dfs2(idx+1);
	
	int act;
	for (act=0; (board[idx] & (1<<act)) != 0; act++);
	
	ll ans = 0ll;
	//vertical
	board[idx] |= (1<<act);
	board[idx+1] |= (1<<act);
	ans += dfs1(idx);
	board[idx] &= ~(1<<act);
	board[idx+1] &= ~(1<<act);
	//horizontal
	if ((act < w-1) && ((board[idx] & (1<<(act+1))) == 0)) {
		board[idx] |= (3<<act);
		ans += dfs1(idx);
		board[idx] &= ~(3<<act);
	}
	return ans;
}

ll dfs2 (int idx) {
	if (idx == h) {
		if (board[idx] == 0) return 1ll;
		else return 0ll;
	}
	if (board[idx] == limitw) return dfs2(idx+1);
	if (DP[idx][board[idx]] != -1ll) return DP[idx][board[idx]];
	return DP[idx][board[idx]] = dfs1(idx);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>h>>w, h || w) {
		if (((h*w) & 1) != 1) {
			memset(DP, -1, sizeof DP);
			memset(board, 0, sizeof board);
			limitw = (1<<w)-1;
			cout<<dfs1(0)<<endl;
		} else cout<<0<<endl;
	}
	
	return 0;
}
