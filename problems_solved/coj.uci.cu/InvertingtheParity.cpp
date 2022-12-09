/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2946
	Name: Inverting the Parity
	Number: 2946
	Date: 24/06/2014
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



int main() {
	
	int t, n;
	
	scanf("%d", &t);
	
	while (t--) {
		
		scanf("%d", &n);
		
		if (n & 1) n <<= 1;
		else while (!(n & 1)) n>>=1;
		
		printf("%d\n", n);
	}
	
	return 0;
}
