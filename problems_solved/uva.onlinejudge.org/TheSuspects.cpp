/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3638
	Name: The Suspects
	Number: 1197
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

int n, m, k, a, b, p[30005], rank[30005], size_set[30005];

int find_set(int i) {return (p[i] == i) ? i : (p[i] = find_set(p[i]));}

void union_set (int i, int j) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		if (rank[x] > rank[y]) {
			p[y] = x;
			size_set[x] += size_set[y];
		} else {
			p[x] = y;
			size_set[y] += size_set[x];
			if (rank[y] == rank[x]) rank[y]++;
		}
	}
}

int main () {
	
	int i, j;
	
	while (scanf("%d %d", &n, &m), n || m) {
		
		for (i=0; i<n; i++) {
			p[i] = i;
			rank[i] = 0;
			size_set[i] = 1;
		}
		
		for (i=0; i<m; i++) {
			scanf("%d", &k);
			if (k) scanf("%d", &a);
			for (j=1; j<k; j++) {
				scanf("%d", &b);
				union_set(a, b);
			}
		}
		
		printf("%d\n", size_set[find_set(0)]);
		
	}
	
	return 0;
}
