/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2166
	Name: Next Round
	Number: 2166
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
#include <fstream>

#define tint unsigned long long int
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9;

using namespace std;

#define INF 1000000000

int n, k, s[100], ans;

int main() {
	
	int t, i, j;
	
	scanf("%d", &t);
	
	while (t--) {
		
		scanf("%d %d", &n, &k);
		
		for (i=0; i<n; i++) 
			scanf("%d", &s[i]);
		
		ans = 0; k--;
		
		for (i=0; (i<n) && (s[i] > 0); i++) 
			ans += ((s[i] > 0) && (s[i] >= s[k]));
		
		printf("%d\n", ans);
		
	}
	
    return 0;
}
