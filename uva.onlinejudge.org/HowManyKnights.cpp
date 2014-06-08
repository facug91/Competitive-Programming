/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=637
	Name: How Many Knights
	Number: 696
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
//
using namespace std;

int m, n, ans, im, in;

int main() {
	
	while (scanf("%d %d", &m, &n), m || n) {
		
		im = m; in = n;
		if (m < n) {m = in; n = im;}
		
		if (n <= 0) ans = 0;
		else if (n == 1) ans = m;
		else if (n == 2) {
			if (m % 4 == 1) ans = m+1;
			else if (m % 4 != 0) ans = m + (4 - (m % 4));
			else ans = m;
		} else ans = (m*n/2)+((m*n)%2);
		
		printf("%d knights may be placed on a %d row %d column board.\n", ans, im, in);
		
	}
	
	return 0;
} 
