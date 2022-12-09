/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1045
	Name: Digits of Factorial
	Number: 1045
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

int n, b;
double rsq[1000005];

void init () {
	rsq[0] = 0.0;
	for (int i=1; i<1000005; i++)
		rsq[i] = rsq[i-1] + log((double) i);
}

int main () {
	int t, i, j;
	
	init();
	
	scanf("%d", &t);
	for (int it=1; it<=t; it++) {
		scanf("%d %d", &n, &b);
		printf("Case %d: %d\n", it, (int) floor(rsq[n]/log((double) b) + 1.0));
	}
	
	return 0;
}
