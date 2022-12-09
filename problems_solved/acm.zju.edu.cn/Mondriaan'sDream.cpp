/*
        By: facug91
        From: http://acm.tju.edu.cn/toj/showp1343.html
        Name: Mondriaan's Dream
        Date: 02/01/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int h, w;
map<vector<int>, ll> DP;
vector<int> board;

bool is_complete () {
	for (int i=0; i<h; i++)
		if (board[i] != ((1<<w)-1))
			return false;
	return true;
}

ll dp () {
	if (DP.find(board) != DP.end()) return DP[board];
	if (is_complete()) return 1;
	int posi, posj; ll ans = 0;
	for (posi=0; posi<h; posi++) {
		if (board[posi] != ((1<<w)-1)) {
			for (posj=0; posj<w; posj++)
				if ((board[posi] & (1<<posj)) == 0)
					break;
			if (posj != w) break;
		}
	}
	board[posi] |= (1<<posj);
	if (posi+1 < h && ((board[posi+1] & (1<<posj)) == 0)) {
		board[posi+1] |= (1<<posj);
		ans += dp();
		board[posi+1] &= ~(1<<posj);
	}
	if (posj+1 < w && ((board[posi] & (1<<(posj+1))) == 0)) {
		board[posi] |= (1<<(posj+1));
		ans += dp();
		board[posi] &= ~(1<<(posj+1));
	}
	board[posi] &= ~(1<<posj);
	DP.insert(make_pair(board, ans));
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>h>>w, h || w) {
		DP.clear();
		board.clear();
		for (i=0; i<h; i++) {
			board.push_back(0);
		}
		cout<<dp()<<endl;
	}
	
	return 0;
}
