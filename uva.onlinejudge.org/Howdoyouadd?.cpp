/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1884
	Name: How do you add?
	Number: 10930
	Date: 17/07/2014
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
#define MOD 1000000
//
using namespace std;

int n, k, DP[101][101];

int dp (int n, int k) {
	if (DP[n][k] != -1) return DP[n][k];
	if (n == 0) return 1;
	if (k == 1) return 1;
	int sum = 0;
	for (int i=0; i<=n; i++)
		sum = (sum + dp(n-i, k-1)) % MOD;
	return (DP[n][k] = sum);
}

int main() {
	int i, j;
	
	while (scanf("%d %d", &n, &k), n || k) {
		memset(DP, -1, sizeof DP);
		printf("%d\n", dp(n, k));
	}
	
	return 0;
} 
