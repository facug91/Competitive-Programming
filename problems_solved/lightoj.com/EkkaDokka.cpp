/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1116
	Name: Ekka Dokka
	Number: 1116
	Date: 25/07/2014
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
//const double PI = 2*acos(0.0);

#define INF 1000000000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

ll w, even, odd;

int main () {
    int t, i, j;
    
    scanf("%d", &t);
    for (int it=1; it<=t; it++) {
		scanf("%lld", &w);
		if ((w == 2) || ((w % 2) != 0)) printf("Case %d: Impossible\n", it);
		else {
			for (even=1, odd=w; (odd%2)==0; even*=2ll) odd /= 2ll;
			printf("Case %d: %lld %lld\n", it, odd, even);
		}
	}
    
    return 0;
}
