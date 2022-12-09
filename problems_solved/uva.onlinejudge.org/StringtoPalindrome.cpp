/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=9
        Name: String to Palindrome
        Number: 10739
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
string s;

int dp (int i, int j) {
	if (DP[i][j] != -1) return DP[i][j];
	if (i >= j) return DP[i][j] = 0;
	if (s[i] == s[j]) return DP[i][j] = dp(i+1, j-1);
	return DP[i][j] = min(min(dp(i+1, j-1), dp(i, j-1)), dp(i+1, j)) + 1;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>s;
		memset(DP, -1, sizeof DP);
		cout<<"Case "<<it<<": "<<dp(0, s.length()-1)<<endl;
	}
	
	return 0;
}

