/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1062
	Name: Laser Sculpture
	Number: 1062
	Date: 18/06/2014
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

int a, c, x0, x1, ans, ant;

int main() {
	
	int i, j;
	
	while (scanf("%d %d", &a, &c), a | c) {
		
		ans = 0;
		scanf("%d", &x0);
		for (i=1; i<c; i++) {
			scanf("%d", &x1);
			if (x1 > x0) ans += x1-x0;
			x0 = x1;
		}
		ans += (a-x0);
		
		printf("%d\n", ans);
	}
	
	return 0;
}
