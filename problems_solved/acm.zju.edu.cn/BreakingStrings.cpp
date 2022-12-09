/*
        By: facug91
        From: Breaking Strings
        Name: http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemId=1860
        Date: 11/02/2015
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
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, x[1005], DP[1005][1005], mid[1005][1005];

int dp () {
	int i, j, l, r;
	for (i=0; i<m; i++) {
		for (l=0; l+i<m; l++) {
			r = l + i;
			if (i < 2) {
				DP[l][r] = 0;
				mid[l][r] = l;
				continue;
			}
			DP[l][r] = MAX_INT;
			for (j=(mid[l][r-1]==l)?l+1:mid[l][r-1]; j<=mid[l+1][r]; j++) {
				if (DP[l][r] > DP[l][j] + DP[j][r] + (x[r] - x[l])) {
					DP[l][r] = DP[l][j] + DP[j][r] + (x[r] - x[l]);
					mid[l][r] = j;
				}
			}
		}
	}
	return DP[0][m-1];
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>n>>m) {
		x[0] = 0;
		for (i=1; i<=m; i++) cin>>x[i];
		x[m+1] = n;
		m += 2;
		cout<<dp()<<endl;
	}
	
	return 0;
}
