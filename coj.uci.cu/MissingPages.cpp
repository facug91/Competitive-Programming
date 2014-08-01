/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2975
	Name: Missing Pages
	Number: 2975
	Date: 11/07/2014
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

int n, p;

int main () {
	int i, j;
	
	while (scanf("%d", &n), n) {
		scanf("%d", &p);
		if (p <= n/2) {
			if (p % 2 == 0) {
				printf("%d %d %d\n", p-1, n-p+1, n-p+2);
			} else {
				printf("%d %d %d\n", p+1, n-p, n-p+1);
			}
		} else {
			if (p % 2 == 0) {
				printf("%d %d %d\n", n-p+1, n-p+2, p-1);
			} else {
				printf("%d %d %d\n", n-p, n-p+1, p+1);
			}
		}
	}
	
	return 0;
}
