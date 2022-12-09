/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1524
	Name: Ubiquitous Religions
	Number: 10583
	Date: 08/07/2014
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

int n, m, p[50005], rank[50005], number_of_sets, a, b;

int find_set (int i) {return (p[i] == i) ? i : (p[i] = find_set(p[i]));}

void union_set (int i, int j) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		number_of_sets--;
		if (rank[x] > rank[y]) {
			p[y] = x;
		} else {
			p[x] = y;
			if (rank[y] == rank[x]) rank[y]++;
		}
	}
}

int main () {
	
	int t = 1, i, j;
	
	while (scanf("%d %d", &n, &m), n | m) {
		
		for (i=1; i<=n; i++)
			p[i] = i, rank[i] = 0;
		number_of_sets = n;
		
		while (m--) {
			scanf("%d %d", &a, &b);
			union_set(a, b);
		}
		
		printf("Case %d: %d\n", t++, number_of_sets);
		
	}
	
	return 0;
}
