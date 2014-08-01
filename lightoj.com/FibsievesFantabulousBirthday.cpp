/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1008
	Name: Fibsieve`s Fantabulous Birthday
	Number: 1008
	Date: 24/07/2014
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
//const long double PI = 2*acos(0);

#define INF 1000000000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

ll s, sqr, diag, x, y;

int main() {
	int t, i, j;
    
    scanf("%d", &t);
    for (int it=1; it<=t; it++) {
		printf("Case %d: ", it);
		scanf("%lld", &s);
		
		sqr = (ll)pow((double)s, 0.5);
		if (sqr*sqr != s) sqr++;
		diag = sqr*sqr-sqr+1;
		x = y = sqr;
		if (diag != s) {
			if (sqr & 1) {
				if (diag > s) y -= (diag-s);
				else x -= (s-diag);
			} else {
				if (diag > s) x -= (diag-s);
				else y -= (s-diag);
			}
		}
		printf("%lld %lld\n", x, y);
	}
    
    return 0;
}
