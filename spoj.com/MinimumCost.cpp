/*
        By: facug91
        From: http://www.spoj.com/problems/MC/
        Name: Minimum Cost
        Number: 15208
        Date: 26/08/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int DP[1005][1005];
string s1, s2;

int dp (int i, int j) {
	if (DP[i][j] != -1) return DP[i][j];
	if (i == (int)s1.length() && j == (int)s2.length()) return DP[i][j] = 0;
	if (i == (int)s1.length()) return DP[i][j] = ((int)s2.length() - j) * 30;
	if (j == (int)s2.length()) return DP[i][j] = ((int)s1.length() - i) * 15;
	if (s1[i] == s2[j]) return DP[i][j] = dp(i+1, j+1);
	return DP[i][j] = min(dp(i+1, j) + 15, dp(i, j+1) + 30);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>s1, s1[0] != '#' || s1.length() != 1) {
		cin>>s2;
		memset(DP, -1, sizeof DP);
		cout<<dp(0, 0)<<endl<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

