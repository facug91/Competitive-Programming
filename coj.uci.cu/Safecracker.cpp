/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2978
	Name: Safecracker
	Number: 2978
	Date: 14/07/2014
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

long long target;
int len;
char s[15], ans[15], aux[15];

bool search (int cant, long long val, int bitmask) {
	if (cant == 5) {
		if (val == target) {
			strcpy(ans, aux);
			return false;
		} else return true;
	}
	
	bool keep = true;
	for (int i=0; (i<len) && (keep); i++) {
		if ((bitmask & (1<<i)) == 0) {
			aux[cant] = s[i];
			keep = search(cant+1, val+((long long)pow(s[i]-'A'+1, cant+1)*((cant%2==0)?1:-1)), bitmask|(1<<i));
		}
	}
	
	return keep;
	
}

int main () {
	int i, j;
	
	while (scanf("%lld %s", &target, s), target || strcmp(s, "END")) {
		
		len = strlen(s);
		
		sort(s, s+len, greater<char>());
		
		memset(aux, 0, sizeof aux);
		ans[0] = 0;
		
		if (search(0, 0, 0)) printf("no solution\n");
		else printf("%s\n", ans);
		
	}
	
	return 0;
}
