/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1099
	Name: War
	Number: 10158
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

int p[10005], e[10005], n, c, x, y;

int find_set (int i) {
	return (p[i] == i) ? i : (p[i] = find_set(p[i]));
}
bool are_friends (int i, int j) {
	return (find_set(i) == find_set(j));
}
bool are_enemies (int i, int j) {
	return (are_friends(i, e[find_set(j)]) || are_friends(j, e[find_set(i)]));
}
void union_friends (int i, int j) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		p[y] = x;
		if ((e[y] != n) && (e[x] != n)) {
			union_friends(e[x], e[y]);
		} else if ((e[y] != n) && (e[x] == n)) {
			e[x] = e[y];
		}
	}
}
void make_enemies (int i, int j) {
	int x = find_set(i);
	int y = find_set(j);
	if ((e[y] == n) && (e[x] == n)) {
		e[y] = x;
		e[x] = y;
	} else if (e[y] == n) {
		e[y] = x;
		union_friends(y, e[x]);
	} else if (e[x] == n) {
		e[x] = y;
		union_friends(x, e[y]);
	} else {
		union_friends(y, e[x]);
		union_friends(x, e[y]);
	}
}

int main () {
	
	int i, j;
	
	scanf("%d", &n);
	
	for (i=0; i<=n; i++) 
		p[i] = i, e[i]=n;
	
	while (scanf("%d %d %d", &c, &x, &y), c) {
		
		switch (c) {
			case 1: 
				if (are_enemies(x, y)) printf("-1\n");
				else union_friends(x, y);
				break;
			case 2:
				if (are_friends(x, y)) printf("-1\n");
				else make_enemies(x, y);
				break;
			case 3:
				printf("%d\n", are_friends(x, y));
				break;
			case 4:
				printf("%d\n", are_enemies(x, y));
				break;
		}
		
	}
	
	return 0;
}
