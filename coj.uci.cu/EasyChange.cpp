/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2616
	Name: Easy Change
	Number: 2616
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

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int n, coin[] = {6, 5, 3, 1}, DP[100005];

int dp (int n) {
	if (n < 0) return INF;
	if (n == 0) return 0;
	if (DP[n] != -1) return DP[n];
	int ans = INF;
	for (int i=0; i<4; i++)
		ans = min(ans, dp(n-coin[i])+1);
	return DP[n] = ans;
}

int main () {
	int t, i, j;
	
	memset(DP, -1, sizeof DP);
	
	scanf("%d", &t);
	for (int it=1; it<=t; it++) {
		scanf("%d", &n);
		printf("Case %d: %d\n", it, dp(n));
	}
	
	return 0;
}
