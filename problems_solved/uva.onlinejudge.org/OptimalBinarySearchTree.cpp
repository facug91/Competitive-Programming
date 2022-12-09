/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1245
        Name: Optimal Binary Search Tree
        Date: 12/02/2015
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

int n, mid[300][300];
ll RSQ[300], DP[300][300];

int dp () {
	int i, j, l, r;
	for (i=0; i<n; i++) {
		for (l=1; l+i<=n; l++) {
			r = l + i;
			if (i < 1) {
				DP[l][r] = 0ll;
				mid[l][r] = l;
				continue;
			}
			DP[l][r] = MAX_LONG;
			for (j=mid[l][r-1]; j<=mid[l+1][r]; j++) {
				ll aux = 0ll;
				if (j == l) aux = DP[j+1][r] + (RSQ[r] - RSQ[j]);
				else if (j == r) aux = DP[l][j-1] + (RSQ[j-1] - RSQ[l-1]);
				else aux = DP[l][j-1] + (RSQ[j-1] - RSQ[l-1]) + DP[j+1][r] + (RSQ[r] - RSQ[j]);
				if (DP[l][r] > aux) {
					DP[l][r] = aux;
					mid[l][r] = j;
				}
			}
		}
	}
	return DP[1][n];
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>n) {
		RSQ[0] = 0ll;
		for (i=1; i<=n; i++) cin>>RSQ[i], RSQ[i] += RSQ[i-1];
		memset(DP, -1, sizeof DP);
		memset(mid, -1, sizeof mid);
		cout<<dp()<<endl;
	}
	
	return 0;
}
