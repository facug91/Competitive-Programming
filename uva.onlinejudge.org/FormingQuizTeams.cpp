/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=21&page=show_problem&problem=1852
	Name: Forming Quiz Teams
	Number: 10911
	Date: 19/06/2014
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

int n, limit;
double graph[17][16], DP[1<<16];
pair<int, int> c[20];
char s[25];

double dist (int x0, int y0, int x1, int y1) {
	return pow((double)((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1)), 0.5);
}

void build_graph () {
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
			graph[i][j] = dist(c[i].first, c[i].second, c[j].first, c[j].second);
}

double dp (int bitmask) {
	if (bitmask == limit)
		return 0;
	
	if (DP[bitmask] != -1)
		return DP[bitmask];
	
	int pos;
	double aux = MAX_DBL;
	for (pos=0; (bitmask & (1<<pos)); pos++);
	
	bitmask |= (1<<pos);
	for (int i=0; i<n; i++)
		if ((bitmask & (1<<i)) == 0)
			aux = min(aux, dp(bitmask|(1<<i))+graph[pos][i]);
	
	bitmask &= ~(1<<pos);
	
	return (DP[bitmask] = aux);
}

int main() {
	
	int t = 1, i, j;
	
	while (scanf("%d", &n), n) {
		
		n *= 2;
		
		for (i=0; i<n; i++)
			scanf("%s %d %d", s, &c[i].first, &c[i].second);
		
		build_graph();
		
		limit = (1 << n) - 1;
		for (i=0; i<(1<<n); i++)
			DP[i] = -1;
		
		printf("Case %d: %.2lf\n", t++, dp(0));
		
	}
	
	return 0;
}
