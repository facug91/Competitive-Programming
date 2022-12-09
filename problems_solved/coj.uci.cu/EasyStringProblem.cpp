/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=
	Name: Easy String Problem
	Number: 2815
	Date: 26/04/2014
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
//#include <bitset>

#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9

#define INF 1000000000
//
using namespace std;

int TC, ans, len, i, j;
bool erased[505];
char t[505], p[505];

int main() {
	
	scanf("%d", &TC);
	
	while (TC--) {
		
		scanf("%s %s", t, p);
		
		ans = -1; len = strlen(p);
		memset(erased, false, sizeof(erased));
		
		do {
			
			ans++;
			i = j = 0;
			
			for (; t[i] && p[j]; i++) {
				if (!erased[i]) {
					if (t[i] == p[j]) j++;
					else if (t[i] == p[0]) j = 1;
					else j = 0;
				}
			}
			
			if (!p[j]) {
				for (--i, --j; j>=0; i--) {
					if (!erased[i] && t[i] == p[j]) {
						erased[i] = true;
						j--;
					}
				}
				j = len;
			}
			
		} while (!p[j]);
		
		printf("%d\n", ans);
		
	}
	
	return 0;
} 
