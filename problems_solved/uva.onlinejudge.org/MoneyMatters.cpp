/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2737
	Name: Money Matters
	Number: 11690
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

using namespace std;

int n, m, p[10010], rank[10010], money[10010], x, y;

int find_set (int i) {return (p[i] == i) ? i : (p[i] = find_set(p[i]));}

void union_set(int i, int j) {
	int x = find_set(i);
	int y = find_set(j);
	if (y != x) {
		if (rank[x] > rank[y]) {
			p[y] = x;
			money[x] += money[y];
		} else {
			p[x] = y;
			money[y] += money[x];
			if (rank[y] == rank[x]) rank[y]++;
		}
	}
}

bool check () {
	for (int i=0; i<n; i++)
		if (money[find_set(i)] != 0)
			return false;
	return true;
}

int main() {
	int t, i, j, k;
	
	scanf("%d", &t);
	
	while (t--) {
		
		scanf("%d %d", &n, &m);
		
		for (i=0; i<n; i++) {
			scanf("%d", money+i);
			p[i] = i;
			rank[i] = 0;
		}
		
		for (i=0; i<m; i++) {
			scanf("%d %d", &x, &y);
			union_set(x, y);
		}
		
		if (check()) printf("POSSIBLE\n");
		else printf("IMPOSSIBLE\n");
		
	}
	
	return 0;
} 
