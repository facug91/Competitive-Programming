/*
        By: facug91
        From: http://www.spoj.com/problems/DIEHARD/
        Name: DIE HARD
        Number: 12471
        Date: 28/08/2014
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
//#define MAXN 6005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int h, a, DP[1010][1500][3], move[3][2];

int dp (int h, int a, int c) {
	if (h <= 0 || a <= 0) return 0;
	if (DP[h][a][c] != -1) return DP[h][a][c];
	return DP[h][a][c] = max(dp(h+move[(c+1)%3][0], a+move[(c+1)%3][1], (c+1)%3), dp(h+move[(c+2)%3][0], a+move[(c+2)%3][1], (c+2)%3)) + 1;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	memset(DP, -1, sizeof DP);
	move[0][0] = 3;
	move[0][1] = 2;
	move[1][0] = -5;
	move[1][1] = -10;
	move[2][0] = -20;
	move[2][1] = 5;
	
	cin>>TC;
	while (TC--) {
		cin>>h>>a;
		cout<<max(max(dp(h+move[0][0], a+move[0][1], 0), dp(h+move[1][0], a+move[1][1], 1)), dp(h+move[2][0], a+move[2][1], 2))<<endl<<endl;
	}
	0;
}

