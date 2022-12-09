/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2900
	Name: LEKTIRA
	Number: 2900
	Date: 02/07/2014
*/

/*
	By: facug91
	From: 
	Name: 
	Number: 
	Date: 
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

char s[100], ans[100], len;

int main() {

	scanf("%s", s);
	
	len = strlen(s);
	ans[0] = 0;
	
	for (int i=1; i<len-1; i++) {
		for (int j=i+1; j<len; j++) {
			reverse(s, s+i);
			reverse(s+i, s+j);
			reverse(s+j, s+len);
			if ((ans[0] == 0) || (strcmp(ans, s) > 0)) strcpy(ans, s);
			reverse(s, s+i);
			reverse(s+i, s+j);
			reverse(s+j, s+len);
		}
	}
	
	printf("%s\n", ans);

	return 0;
}
