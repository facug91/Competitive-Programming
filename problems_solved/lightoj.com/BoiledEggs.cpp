/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1227
	Name: Boiled Eggs
	Number: 1227
	Date: 25/07/2014
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
//const double PI = 2*acos(0.0);

#define INF 1000000000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int n, p, q, egg[35], DP[35][500];

int dp (int idx, int w) {
	if (idx == n) return 0;
	if (q < w+egg[idx]) return 0;
	if (DP[idx][w] != -1) return DP[idx][w];
	return DP[idx][w] = max(dp(idx+1, w+egg[idx])+1, dp(idx+1, w));
}

int main () {
    int t, i, j;
    
    scanf("%d", &t);
    for (int it=1; it<=t; it++) {
		scanf("%d %d %d", &n, &p, &q);
		for (i=0; i<n; i++)
			scanf("%d", egg+i);
		memset(DP, -1, sizeof DP);
		printf("Case %d: %d\n", it, min(dp(0, 0), p));
	}
    
    return 0;
}
