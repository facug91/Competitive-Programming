/*
	By: facug91
	From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1130
	Name: Minesweeper
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

int n, m, dx[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[] = {1, 1, 0, -1, -1, -1, 0, 1}, cnt;
string mat[105];

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	while (cin>>n>>m, n || m) {
		if (tc != 1) cout<<endl;
		for (i=0; i<n; i++) cin>>mat[i];
		for (i=0; i<n; i++) for (j=0; j<m; j++) {
			if (mat[i][j] == '*') continue;
			cnt = 0;
			for (int d=0; d<8; d++) {
				int x = i + dx[d];
				int y = j + dy[d];
				if (x >= 0 && y >= 0 && x < n && y < m && mat[x][y] == '*') cnt++;
			}
			mat[i][j] = (char)(cnt+'0');
		}
		cout<<"Field #"<<tc++<<":"<<endl;
		for (i=0; i<n; i++) cout<<mat[i]<<endl;
	}
	
	return 0;
}
