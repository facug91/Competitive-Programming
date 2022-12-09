/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2973
	Name: Digit Sum
	Number: 2973
	Date: 12/07/2014
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

int n, digits[15], p;
list<int> num[2];
list<int>::iterator itrl[2];

int main () {
	int i, j;
	
	while (scanf("%d", &n), n) {
		
		num[0].clear();
		num[1].clear();
		
		for (i=0; i<n; i++)
			scanf("%d", digits+i);
			
		sort(digits, digits+n, greater<int>());
		
		p = 0;
		for (i=0; (i<n) && digits[i]; i++) {
			num[p].push_back(digits[i]);
			p = (p+1)%2;
		}
		if ((i != n) && (num[0].size() > num[1].size()))
			num[1].insert(--num[1].end(), digits[i++]);
		p = 1;
		itrl[0] = --num[0].end();
		itrl[1] = --num[1].end();
		for (; i<n; i++) {
			num[p].insert(itrl[p], digits[i]);
			p = (p+1)%2;
		}
		long long ans = 0;
		for (j=0; j<2; j++) {
			for (i=1, itrl[j]=num[j].begin(); itrl[j]!=num[j].end(); itrl[j]++, i*=10)
				ans += ((*(itrl[j]))*i);
		}
		printf("%lld\n", ans);
		
	}
	
	return 0;
}
