/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2910
	Name: Tobby and the Divisors II
	Number: 2910
	Date: 13/07/2014
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
#define MAXN 1000010

using namespace std;

int a, n, ans[1000010];
long long divs[1000010];

void init () {
	int i, j, k;
	divs[0] = 0; ans[0] = 0;
	for (i=1; i<MAXN; i++)
		divs[i] = 1, ans[i] = i;
	for (i=2; i<MAXN; i++)
		for (j=i; j<MAXN; j+=i)
			divs[j]++;
	for (i=1; i<MAXN; i++)
		if (divs[i] <= divs[i-1]) {
			divs[i] = divs[i-1];
			ans[i] = ans[i-1];
		}
}

int main () {
	int i, j;
	
	init();
	
	scanf("%d", &a);
	
	while (a--) {
		
		scanf("%d", &n);
		
		printf("%d\n", ans[n]);
		
	}
	
	return 0;
}
