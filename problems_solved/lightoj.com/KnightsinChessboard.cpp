/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1010
	Name: Knights in Chessboard
	Number: 1010
	Date: 24/07/2014
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iterator>
#include <utility>
#include <list>
#include <stack>
#include <iomanip>
#include <bitset>

#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
//const long double PI = 2*acos(0);

#define INF 1000000000
#define MOD 10000007

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int n, m, memo[205][205];

int init () {
	int i, j;
	memo[1][1] = 1;
	memo[2][1] = memo[1][2] = 2;
	memo[2][2] = 4;
	for (i=3; i<=200; i++) {
		memo[1][i] = memo[i][1] = i;
		if (i % 4 == 1) memo[2][i] = memo[i][2] = (i/4)*4+2;
		else if (i % 4 == 2) memo[2][i] = memo[i][2] = (i/4)*4+4;
		else memo[2][i] = memo[i][2] = memo[i-1][2];
		for (j=3; j<=200; j++)
			memo[i][j] = memo[j][i] = ((i*j)/2)+((i*j)%2);
	}
}

int main () {
	int t, i, j;
	
	init();
	
	scanf("%d", &t);
	for (int it=1; it<=t; it++) {
		scanf("%d %d", &n, &m);
		printf("Case %d: %d\n", it, memo[n][m]);
	}
	
	return 0;
}
