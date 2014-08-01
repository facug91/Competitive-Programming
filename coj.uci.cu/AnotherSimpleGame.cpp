/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2879
	Name: Another Simple Game
	Number: 2879
	Date: 27/06/2014
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
#include <fstream>

#define tint unsigned long long int
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9;

using namespace std;

#define INF 1000000000

long long n, m;

int main() {
	
	int t;
	
	scanf("%d", &t);
	
	while (t--) {
		
		scanf("%lld %lld", &n, &m);
		
		if ((m % n) == 0) printf("%lld %lld\n", n, m);
		else printf("-1\n");
		
	}
	
    return 0;
}
