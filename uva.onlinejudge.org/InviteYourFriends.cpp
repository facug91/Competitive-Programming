/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3222
        Name: Invite Your Friends
        Date: 03/03/2016
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
#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, f, t, city[25][25], DP[5][26][25][25], x, y, dx[] = {0, 0, 1, 0, -1}, dy[] = {0, 1, 0, -1, 0}, ans, sum, loc;
ii friends[5], cc;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j, k, l, d;
	
	while (cin>>n>>f>>t, n || f || t) {
		for (i=0; i<n; i++) for (j=0; j<n; j++) cin>>city[i][j];
		for (i=0; i<f; i++) cin>>friends[i].F>>friends[i].S;
		for (i=0; i<f; i++) for (j=0; j<=t; j++) for (k=0; k<n; k++) for (l=0; l<n; l++) DP[i][j][k][l] = INF;
		for (i=0; i<f; i++) {
			DP[i][0][friends[i].F][friends[i].S] = city[friends[i].F][friends[i].S];
			for (j=1; j<=t; j++) for (k=0; k<n; k++) for (l=0; l<n; l++) for (d=0; d<5; d++) {
				x = k + dx[d];
				y = l + dy[d];
				if (x >= 0 && x < n && y >= 0 && y < n) DP[i][j][k][l] = min(DP[i][j][k][l], DP[i][j-1][x][y] + city[k][l]);
			}
		}
		ans = INF;
		for (k=0; k<n; k++) for (l=0; l<n; l++) {
			sum = 0;
			for (i=0; i<f; i++) {
				loc = INF;
				for (j=0; j<=t; j++) {
					loc = min(loc, DP[i][j][k][l]);
				}
				if (loc == INF) {
					sum = INF;
					break;
				}
				sum += loc - city[k][l];
			}
			if (ans > sum) {
				ans = sum;
				cc = ii(k, l);
			}
		}
		if (ans == INF) cout<<"Case #"<<tc++<<": Impossible."<<endl;
		else cout<<"Case #"<<tc++<<": Selected city ("<<cc.F<<","<<cc.S<<") with minimum cost "<<ans<<"."<<endl;
	}
	
	return 0;
}
