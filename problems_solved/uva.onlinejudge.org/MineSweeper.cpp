/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1220
        Name: Mine Sweeper
        Date: 31/12/2015
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

int n, dx[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
string mat[15], mov[15];

int calc (int x, int y) {
	int w, z, ans = 0;
	for (int d=0; d<8; d++) {
		w = x + dx[d];
		z = y + dy[d];
		if (w >= 0 && w < n && z >= 0 && z < n && mat[w][z] == '*') ans++;
	}
	return ans;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n;
		for (i=0; i<n; i++) cin>>mat[i];
		for (i=0; i<n; i++) cin>>mov[i];
		bool mine = false;
		for (i=0; i<n; i++) for (j=0; j<n; j++) if (mat[i][j] == '*' && mov[i][j] == 'x') mine = true;
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++) {
				if (mat[i][j] == '*') {
					if (mine) cout<<"*";
					else cout<<".";
				} else {
					if (mov[i][j] == '.') cout<<'.';
					else cout<<calc(i, j);
				}
			}
			cout<<endl;
		}
		if (tc) cout<<endl;
	}
	
	return 0;
}
