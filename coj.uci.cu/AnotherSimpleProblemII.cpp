/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2803
	Name: Another Simple Problem II
	Number: 2803
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
char s[15][15];

bool check () {
	int i, j, k;
	
	for (i=0; i<n; i++)
		for (j=0; j<n-1; j++) 
			if ((s[i][j] == s[i][j+1]) || (s[j][i] == s[j+1][i])) return false;
	
	return true;
}

int main () {
	
	int t, i, j;
	
	scanf("%d", &t);
	
	while (t--) {
		
		scanf("%d", &n);
		for (i=0; i<n; i++)
			scanf("%s", s[i]);
		
		if (check()) printf("YES\n");
		else printf("NO\n");
		
	}
	
	return 0;
}
