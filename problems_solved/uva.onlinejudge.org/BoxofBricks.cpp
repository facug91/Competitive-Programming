/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=532
	Name: Box of Bricks
	Number: 591
	Date: 07/07/2014
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

using namespace std;

int n, h[105], sum, prom, ans;

int main () {
	
	int t = 1, i, j;
	
	while (scanf("%d", &n), n) {
		
		sum = 0;
		for (i=0; i<n; i++) {
			scanf("%d", h+i);
			sum += h[i];
		}
		
		prom = sum / n; ans = 0;
		for (i=0; i<n; i++) 
			ans += abs(prom-h[i]);
		ans /= 2;
		
		printf("Set #%d\nThe minimum number of moves is %d.\n\n", t++, ans);
		
	}
	
	return 0;
}
