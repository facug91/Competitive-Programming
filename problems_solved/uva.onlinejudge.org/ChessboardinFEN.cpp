/*
	By: facug91
	From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1225
	Name: Chessboard in FEN
	Date: 16/11/2015
*/

#include <bits/stdc++.h>
#define next asjkdbg1238dv8ydf38gy832gf8yd
#define prev asjkdbuiqdg783gdiu3dg79832dui
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define endl "\n"
#define DB(x) cerr << "#" << (#x) << ": " << (x) << " "
#define DBL(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10000100

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi; typedef vector<ii> vii;		   typedef vector<iii> viii;

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
int nx[] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[] = {2, 1, -1, -2, -2, -1, 1, 2};
bool mat[8][8], ans[8][8];
string FEN;
char board[8][8];

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	while (cin>>FEN) {
		memset(board, 0, sizeof board);
		memset(mat, 0, sizeof mat);
		memset(ans, 0, sizeof ans);
		i = j = 0;
		for (char fen : FEN) {
			if (fen == '/') {
				i++; j = 0;
			} else {
				if (fen >= '0' && fen <= '9') j += fen-'0';
				else {
					board[i][j] = fen;
					mat[i][j] = ans[i][j] = true;
					j++;
				}
			}
		}
		for (i=0; i<8; i++) for (j=0; j<8; j++) {
			if (!mat[i][j]) continue;
			switch (board[i][j]) {
				case 'k':
				case 'K':
					for (int d=0; d<8; d++) {
						int x = i+dx[d];
						int y = j+dy[d];
						if (x >= 0 && x < 8 && y >= 0 && y < 8) ans[x][y] = true;
					}
					break;
				case 'q':
				case 'Q':
					for (int d=0; d<8; d++) {
						int x = i+dx[d];
						int y = j+dy[d];
						while (x >= 0 && x < 8 && y >= 0 && y < 8 && !mat[x][y]) {
							ans[x][y] = true;
							x += dx[d];
							y += dy[d];
						}
					}
					break;
				case 'r':
				case 'R':
					for (int d=0; d<8; d+=2) {
						int x = i+dx[d];
						int y = j+dy[d];
						while (x >= 0 && x < 8 && y >= 0 && y < 8 && !mat[x][y]) {
							ans[x][y] = true;
							x += dx[d];
							y += dy[d];
						}
					}
					break;
				case 'b':
				case 'B':
					for (int d=1; d<8; d+=2) {
						int x = i+dx[d];
						int y = j+dy[d];
						while (x >= 0 && x < 8 && y >= 0 && y < 8 && !mat[x][y]) {
							ans[x][y] = true;
							x += dx[d];
							y += dy[d];
						}
					}
					break;
				case 'n':
				case 'N':
					for (int d=0; d<8; d++) {
						int x = i+nx[d];
						int y = j+ny[d];
						if (x >= 0 && x < 8 && y >= 0 && y < 8) ans[x][y] = true;
					}
					break;
				case 'p':
					if (i < 7 && j < 7) ans[i+1][j+1] = true;
					if (i < 7 && j > 0) ans[i+1][j-1] = true;
					break;
				case 'P':
					if (i > 0 && j < 7) ans[i-1][j+1] = true;
					if (i > 0 && j > 0) ans[i-1][j-1] = true;
					break;
			}
		}
		int cnt = 0;
		for (i=0; i<8; i++) for (j=0; j<8; j++) if (!ans[i][j]) cnt++;
		cout<<cnt<<endl;
	}
	
	return 0;
}
