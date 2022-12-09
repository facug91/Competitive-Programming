/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3158
        Name: Cow Hopscotch
        Date: 13/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int r, c, k, mat[105][105];
ll DP[105][105];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, j, k, l;
	
	cin>>r>>c>>k;
	for (i=0; i<r; i++) for (j=0; j<c; j++) cin>>mat[i][j];
	for (i=0; i<r; i++) DP[i][c-1] = 0ll;
	for (i=0; i<c; i++) DP[r-1][i] = 0ll;
	DP[r-1][c-1] = 1ll;
	for (i=r-2; i>=0; i--) {
		for (j=c-2; j>=0; j--) {
			DP[i][j] = 0ll;
			for (k = i+1; k<r; k++)
				for (l=j+1; l<c; l++)
					if (mat[i][j] != mat[k][l] && DP[k][l] != 0ll)
						DP[i][j] = (DP[i][j] + DP[k][l]) % MOD;
		}
	}
	cout<<DP[0][0]<<"\n";
	
	return 0;
}
