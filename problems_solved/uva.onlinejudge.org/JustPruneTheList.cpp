/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3200
	Name: Just Prune The List
	Number: 12049
	Date: 09/07/2014
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

using namespace std;

int n, m, list1[10005], list2[10005], ans;

int main () {
	
	int t, i, j;
	
	scanf("%d", &t);
	
	while (t--) {
		scanf("%d %d", &n, &m);
		
		for (i=0; i<n; i++) 
			scanf("%d", list1+i);
		
		for (i=0; i<m; i++)
			scanf("%d", list2+i);
		
		sort (list1, list1+n);
		sort (list2, list2+m);
		
		ans = i = j = 0;
		while ((i<n) && (j<m)) {
			if (list1[i] == list2[j]) i++, j++;
			else if (list1[i] > list2[j]) j++, ans++;
			else i++, ans++;
		}
		if (i != n) ans += (n-i);
		if (j != m) ans += (m-j);
		
		printf("%d\n", ans);
		
	}
	
	return 0;
}
