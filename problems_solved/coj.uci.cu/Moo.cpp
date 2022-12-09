/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1969
	Name: Moo
	Number: 1969
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

long long n, s[30];
char ans;

void init () {
	s[0] = 3; 
	for (int i=1; s[i-1]<=1000000000; i++)
		s[i] = s[i-1] * 2 + i + 3;
}

char solve (long long n) {
	long long i;
	
	if (n <= 3) {
		if (n == 1) return 'm';
		else return 'o';
	}
	
	for (i=1; s[i]<n; i++);
	
	if (s[i-1]+i+4 <= n) return solve(n-(s[i-1]+i+3));
	else if (n == s[i-1]+1) return 'm';
	else return 'o';
	
}

int main() {
	
	init();
	
	scanf("%lld", &n);
	
	ans = solve(n);
	
	printf("%c\n", ans);
	
	return 0;
} 
