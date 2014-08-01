/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1006
	Name: Hex-a-bonacci
	Number: 1006
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

int n, DP[10005];
int fn (int n) {
	if (DP[n] != -1) return DP[n];
    return DP[n] = ((((((((((fn(n-1) + fn(n-2)) % MOD) + fn(n-3)) % MOD) + fn(n-4)) % MOD) + fn(n-5)) % MOD) + fn(n-6)) % MOD);
}
int main() {
	int t, i, j;
    
    scanf("%d", &t);
    for (int it=1; it<=t; it++) {
        memset(DP, -1, sizeof DP);
		for (i=0; i<6; i++) {
			scanf("%d", DP+i);
			DP[i] %= MOD;
		}
		scanf("%d", &n);
        printf("Case %d: %d\n", it, fn(n));
    }
    return 0;
}
