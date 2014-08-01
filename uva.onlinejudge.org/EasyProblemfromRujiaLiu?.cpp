/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3142
	Name: Easy Problem from Rujia Liu?
	Number: 11991
	Date: 18/07/2014
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
//
using namespace std;

int n, m, a, k, v;
vector<int> ans[1000010];

int main() {
	int i, j;
	
	while (scanf("%d %d", &n, &m) != EOF) {
		
		for (i=0; i<=1000000; i++)
			ans[i].clear();
		
		for (i=1; i<=n; i++) {
			scanf("%d", &a);
			ans[a].push_back(i);
		}
		
		for (i=0; i<m; i++) {
			scanf("%d %d", &k, &v);
			if (ans[v].size() < k) printf("0\n");
			else printf("%d\n", ans[v][k-1]);
		}
		
	}
	
	return 0;
} 
