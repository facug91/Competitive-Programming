/*
        By: facug91
        From: http://www.spoj.com/problems/EELCS/
        Name: Easy Longest Common Subsequence
        Date: 01/02/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int LCS[10][10];
string a, b;

int lcs () {
	int n = a.length(), m = b.length(), i, j;
	memset(LCS, 0, sizeof LCS);
	for (i=1; i<=n; i++) {
		for (j=1; j<=m; j++) {
			if (a[i-1] == b[j-1]) LCS[i][j] = LCS[i-1][j-1] + 1;
			else LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
		}
	}
	return LCS[n][m];
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>a;
	cin>>b;
	cout<<lcs()<<endl;
	
	return 0;
}
