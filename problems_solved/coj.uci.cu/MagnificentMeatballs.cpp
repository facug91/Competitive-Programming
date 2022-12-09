/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2976
	Name: Magnificent Meatballs
	Number: 2976
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

using namespace std;

int n;
long long host[35], sam, ella;

int main () {
	int t, i, j;
	
	while (scanf("%d", &n), n) {
		
		ella = 0;
		for (i=0; i<n; i++) {
			scanf("%lld", host+i);
			ella += host[i];
		}
		sam = 0;
		for (i=0; i<n-1; i++) {
			sam += host[i];
			ella -= host[i];
			if (sam == ella) break;
		}
		
		if (i != n-1) printf("Sam stops at position %d and Ella stops at position %d.\n", i+1, i+2);
		else printf("No equal partitioning.\n");
		
	}
	
	return 0;
}
