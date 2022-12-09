/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2444
	Name: Binary Genocide
	Number: 2444
	Date: 09/07/2014
*/

/*
	By: facug91
	From: 
	Name: 
	Number: 
	Date: 28/06/2014
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

bool even[1001];

int init () {
	int cont, n;
	for (int i=0; i<1001; i++) {
		cont = 0; n = i;
		while (n) {
			cont += (n & 1);
			n >>= 1;
		}
		even[i] = (cont % 2 == 0);
	}
}

int main () {
	init();
	int n, ans = 0;
	while (scanf("%d", &n) != EOF)
		ans += even[n];
	printf("%d\n", ans);
	
	return 0;
}
