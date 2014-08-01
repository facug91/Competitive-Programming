/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=442
	Name: Black Box
	Number: 501
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

int m, n, a[30005], u[30005], ix;
multiset<int> used;
multiset<int>::iterator its;

int main() {
	
	int k, i, j;
	
	scanf("%d", &k);
	
	while (k--) {
		
		scanf("%d %d", &m, &n);
		
		for (i=0;i<m; i++)
			scanf("%d", &a[i]);
			
		for (i=0;i<n; i++)
			scanf("%d", &u[i]);
		
		j = 0;
		its = used.begin();
		for (i=0; i<n; i++) {
			for (; j<u[i]; j++) {
				used.insert(a[j]);
				if ((its == used.end()) || (a[j] < (*its))) its--;
			}
			printf("%d\n", (*its));
			its++;
		}
		
		if (k) {
			used.clear();
			printf("\n");
		}
	}
	
	return 0;
}
