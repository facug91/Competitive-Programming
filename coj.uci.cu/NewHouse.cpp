/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=1002
        Name: New House
        Date: 10/02/2015
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

int n, DP[1005][1005];
string mat[1005];

int dp () {
	int i, j, ans;
	DP[0][0] = (mat[0][0] == '.') ? 1 : 0;
	for (i=0; i<n; i++) DP[i][0] = (mat[i][0] == '#') ? 0 : 1;
	for (j=0; j<n; j++) DP[0][j] = (mat[0][j] == '#') ? 0 : 1;
	for (i=1; i<n; i++)
		for (j=1; j<n; j++)
			DP[i][j] = (mat[i][j] == '#') ? 0 : (min(DP[i-1][j-1], min(DP[i-1][j], DP[i][j-1])) + 1);
	ans = -1;
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			ans = max(ans, DP[i][j]);
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n;
		for (i=0; i<n; i++) cin>>mat[i];
		cout<<dp()<<endl;
	}
	
	return 0;
}
