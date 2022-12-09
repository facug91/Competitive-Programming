/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2154
	Name: Another Simple Problem
	Number: 2154
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

int n;
char s[80][80];
bool used['z'+1];

bool check (int b) {
	
	if ((n-b-b) == 1) return (!used[s[b][b]]);
	
	char c = s[b][b];
	
	if (used[c]) return false;
	
	used[c] = true;
	for (int i=0+b; i<n-b; i++)
		if ((s[b][i] != c) || (s[i][b] != c) || (s[n-b-1][i] != c) || (s[i][n-b-1] != c)) return false;
	
	if ((n-b-b-2) > 0) return check(b+1);
	
	return true;
	
}

int main () {
	
	int t, i, j;
	
	scanf("%d", &t);
	
	while (t--) {
		
		memset(used, 0, sizeof used);
		
		scanf("%d", &n);
		for (i=0; i<n; i++)
			scanf("%s", s[i]);
		
		if (check(0)) printf("YES\n");
		else printf("NO\n");
		
	}
	
	return 0;
}
