/*
	By: facug91
	From: Find Phones
	Name: http://coj.uci.cu/24h/problem.xhtml?abb=2943
	Number: 2943
	Date: 01/07/2014
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

int p[505], rank[505], tel[505];
int n, a, b;

int find_set (int i) {return (p[i] == i) ? i : p[i]=find_set(p[i]);}
bool same_set (int i, int j) {return find_set(i) == find_set(j);}
void union_set (int i, int j) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		if (rank[x] > rank[y]) {
			p[y] = x;
			if (tel[x] == 0) tel[x] = tel[y];
		} else {
			p[x] = y;
			if (tel[y] == 0) tel[y] = tel[x];
			if (rank[y] == rank[x]) rank[y]++;
		}
	}
}

int main() {
	
	int i, j, k;
	
	scanf("%d", &n);
	
	for (i=1; i<=n; i++) {
		p[i] = i; rank[i] = 0;
		scanf("%d", tel+i);
	}
	
	while (scanf("%d %d", &a, &b) != EOF) 
		union_set(a, b);
	
	for (i=1; i<=n; i++)
		printf("%d\n", tel[find_set(i)]);
	
	return 0;
}
