/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2515
        Name: Fill the Square
        Date: 07/04/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
string grid[15];
char act;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10);
	int tc, i, j, k, l, x, y;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n;
		for (i=0; i<n; i++) cin>>grid[i];
		for (i=0; i<n; i++) for (j=0; j<n; j++) if (grid[i][j] == '.') {
			act = 'A';
			for (k=0; k<4; k++) for (l=0; l<4; l++) {
				x = i + dx[l];
				y = j + dy[l];
				if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == act) act++;
			}
			grid[i][j] = act;
		}
		cout<<"Case "<<it<<":\n";
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++) cout<<grid[i][j];
			cout<<"\n";
		}
	}
	
	return 0;
}
