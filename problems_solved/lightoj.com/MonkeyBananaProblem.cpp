/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1004
	Name: Monkey Banana Problem
	Number: 1004
	Date: 29/07/2014
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

int n;
ll arr[205][105];

int main () {
	int t, i, j;
	
	scanf("%d", &t);
	for (int it=1; it<=t; it++) {
		scanf("%d", &n);
		memset(arr, 0, sizeof arr);
		for (i=0; i<n; i++)
			for (j=0; j<i+1; j++)
				scanf("%lld", &arr[i][j]);
		for (i=0; i<n-1; i++)
			for (j=0; j<n-i-1; j++)
				scanf("%lld", &arr[i+n][j]);
		for (i=1; i<n; i++)
			for (j=0; j<i+1; j++)
				arr[i][j] += max(arr[i-1][j-1], arr[i-1][j]);
		for (i=0; i<n-1; i++)
			for (j=0; j<n-i-1; j++)
				arr[i+n][j] += max(arr[i+n-1][j], arr[i+n-1][j+1]);
		printf("Case %d: %lld\n", it, arr[n*2-2][0]);
	}
	
	return 0;
}
