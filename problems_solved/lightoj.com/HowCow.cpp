/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1107
	Name: How Cow
	Number: 1107
	Date: 24/07/2014
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
//#include <cmath>
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
#define MOD 10000007

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int x1, y1, x2, y2, m, x0, y0;

int main () {
	int t, i, j;
	
	scanf("%d", &t);
	for (int it=1; it<=t; it++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		scanf("%d", &m);
		printf("Case %d:\n", it);
		for (i=0; i<m; i++) {
			scanf("%d %d", &x0, &y0);
			if ((x0 > x1) && (x0 < x2) && (y0 > y1) && (y0 < y2)) printf("Yes\n");
			else printf("No\n");
		}
	}
	
	return 0;
}
