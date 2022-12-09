/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2491
	Name: Musical Loop
	Number: 11496
	Date: 02/07/2014
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

int n, h[10005], ans;
bool up;

int main() {
	
	int i, j;
	
	while (scanf("%d", &n), n) {
		
		for (i=0; i<n; i++)
			scanf("%d", h+i);
		
		ans = 0;
		up = h[n-1] < h[0];
		for (i=0; i<n-1; i++) {
			if (h[i] < h[i+1]) {
				if (!up) {
					ans++;
					up = true;
				}
			} else {
				if (up) {
					ans++;
					up = false;
				}
			}
		}
		if (h[n-1] < h[0]) {
			if (!up) {
				ans++;
				up = true;
			}
		} else {
			if (up) {
				ans++;
				up = false;
			}
		}
		
		printf("%d\n", ans);
		
	}
	
	return 0;
}
