/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1189
	Name: Sum of Factorials
	Number: 1189
	Date: 02/08/2014
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
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

ll n, factorial[20];

int search () {
	int ans = 0;
	for (int i=19; i>=0; i--) {
		if (n >= factorial[i]) {
			ans |= (1<<i);
			n -= factorial[i];
		}
	}
	if (n != 0) return -1;
	return ans;
}

void init () {
	int i, j;
	factorial[0] = 1;
	for (i=1; i<20; i++)
		factorial[i] = i*factorial[i-1];
}


int main () {
	int t, i, j;
	
	init();
	
	scanf("%d", &t);
	for (int it=1; it<=t; it++) {
		scanf("%lld", &n);
		int bitmask = search();
		if (bitmask == -1) printf("Case %d: impossible\n", it);
		else {
			printf("Case %d: ", it);
			bool first = true;
			for (i=0; i<20; i++) {
				if (bitmask & (1<<i)) {
					if (first) {
						first = false;
						printf("%d!", i);
					} else printf("+%d!", i);
				}
			}
			printf("\n");
		}
	}
	
	return 0;
}
