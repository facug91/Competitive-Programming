/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1205
	Name: The Most Potent Corner
	Number: 10264
	Date: 19/06/2014
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
#define _log2(x) log(x) * 1.44269504088896340736
//const long double PI = 2*acos(0);

#define INF 1000000000
//
using namespace std;

int n, cube[1<<14], sum[1<<14], ans;

int main() {
	
	int i, j;
	
	while (scanf("%d", &n) != EOF) {
		
		for (i=0; i<(1<<n); i++) {
			scanf("%d", &cube[i]);
			sum[i] = 0;
		}
		
		for (i=0; i<(1<<n); i++)
			for (j=0; j<n; j++)
				sum[i^(1<<j)] += cube[i];
		
		ans = -1;
		for (i=0; i<(1<<n); i++)
			for (j=0; j<n; j++)
				if (sum[i^(1<<j)]+sum[i] > ans)
					ans = sum[i^(1<<j)]+sum[i];
		
		printf("%d\n", ans);
		
	}
	
	return 0;
}
