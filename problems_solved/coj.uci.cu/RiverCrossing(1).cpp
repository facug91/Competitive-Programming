/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2484
	Name: River Crossing
	Number: 2484
	Date: 02/08/2014
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
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int n, m, cow[2505], DP[2505][2505];

int dp (int n, int act) {
	if (n == 0) return 0;
	if (DP[n][act] != -1) return DP[n][act];
	if (act == n) return DP[n][act] = cow[act]+m*2;
	return DP[n][act] = min(dp(n-(act+1), 0)+cow[act+1]+m*2, dp(n, act+1));
}

int main () {
	int t, i, j;
	
	memset(DP, -1, sizeof DP);
	scanf("%d %d", &n, &m);
	for (i=1; i<=n; i++)
		scanf("%d", cow+i);
	for (i=2; i<=n; i++)
		cow[i] += cow[i-1];
	printf("%d\n", dp(n, 0)-m);
	
	return 0;
}
