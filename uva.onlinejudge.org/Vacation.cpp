/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1133
        Name: Vacation
        Number: 10192
        Date: 22/08/2014
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

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int LCS[105][105];
string s1, s2;

int lcs () {
	int i, j, size1 = (int)s1.size(), size2 = (int)s2.size();
	for (i=0; i<=size1; i++) LCS[0][i] = 0;
	for (i=0; i<=size2; i++) LCS[i][0] = 0;
	for (i=1; i<=size1; i++) {
		for (j=1; j<=size2; j++) {
			if (s1[i-1] == s2[j-1]) LCS[i][j] = LCS[i-1][j-1]+1;
			else LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
		}
	}
	return LCS[size1][size2];
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC = 1, i, j;
	
	while (getline(cin, s1), s1[0] != '#') {
		getline(cin, s2);
		cout<<"Case #"<<TC++<<": you can visit at most "<<lcs()<<" cities.\n";
	}
	
	return 0;
}
