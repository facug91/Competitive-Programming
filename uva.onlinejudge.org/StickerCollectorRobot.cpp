/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2931
        Name: Sticker Collector Robot
        Date: 20/01/2015
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-2
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, m, s, p, q, o, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, ans;
string mat[105], moves;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	while (cin>>n>>m>>s, n || m || s) {
		for (i=0; i<n; i++) cin>>mat[i];
		cin>>moves;
		for (i=0; i<n; i++) for (j=0; j<m; j++) {
			if (mat[i][j] != '.' && mat[i][j] != '*' && mat[i][j] != '#') {
				p = i;
				q = j;
				if (mat[i][j] == 'L') o = 0;
				else if (mat[i][j] == 'S') o = 1;
				else if (mat[i][j] == 'O') o = 2;
				else o = 3;
				mat[i][j] = '.';
			}
		}
		//cout<<"p "<<p<<" q "<<q<<" o "<<o<<endl;
		ans = 0;
		for (i=0; i<moves.length(); i++) {
			if (moves[i] == 'D') { // Right
				o = (o + 1) % 4;
			} else if (moves[i] == 'E') { // Left 
				o = (o + 4 - 1) % 4;
			} else { // Move Forward 
				int x = p + dx[o];
				int y = q + dy[o];
				if (x >= 0 && x < n && y >= 0 && y < m && mat[x][y] != '#') {
					p = x;
					q = y;
					if (mat[p][q] == '*') {
						ans++;
						mat[p][q] = '.';
					}
				}
			}
			//cout<<"p "<<p<<" q "<<q<<" o "<<o<<" ans "<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
