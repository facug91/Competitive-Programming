/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2183
	Name: Tour de France
	Number: 11242
	Date: 22/06/2014
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

int f, r, front[11], raer[11];
double drive_ratio[105], ans;

int main() {
	
	int i, j, k;
	
	while (scanf("%d", &f), f) {
		
		scanf("%d", &r);
		
		for (i=0; i<f; i++)
			scanf("%d", &front[i]);
			
		for (i=0; i<r; i++)
			scanf("%d", &raer[i]);
		
		k = 0;
		for (i=0; i<f; i++)
			for (j=0; j<r; j++)
				drive_ratio[k++] = (double) raer[j]/front[i];
		
		sort(drive_ratio, drive_ratio+k);
		
		ans = 0.0;
		for (i=1; i<k; i++)
			ans = max(ans, drive_ratio[i]/drive_ratio[i-1]);
		
		printf("%.2lf\n", ans);
	}
	
	return 0;
}
