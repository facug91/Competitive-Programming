/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1318
        Name: Maze Traversal
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

int n, m, p, q, o, dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
string line, maze[70], com, orientation = "NESW";
bool finish;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n>>m;
		getline(cin, line);
		for (i=0; i<n; i++) getline(cin, maze[i]);
		cin>>p>>q; p--; q--;
		o = 0;
		getline(cin, line);
		finish = false;
		while (getline(cin, com) && com.length()) {
			if (finish) continue;
			for (i=0; i<com.length(); i++) {
				if (com[i] == 'Q') {
					cout<<p+1<<" "<<q+1<<" "<<orientation[o]<<endl;
					finish = true;
					break;
				} else if (com[i] == 'R') {
					o = (o + 1) % 4;
				} else if (com[i] == 'L') {
					o = (o + 4 - 1) % 4;
				} else if (com[i] == 'F') {
					int x = p + dx[o];
					int y = q + dy[o];
					if (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] != '*') {
						p = x;
						q = y;
					}
				}
			}
		}
		if (tc) cout<<endl;
	}
	
	return 0;
}
