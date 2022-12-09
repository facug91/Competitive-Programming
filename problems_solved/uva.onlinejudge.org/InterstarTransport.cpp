/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3688
	Name: Interstar Transport
	Number: 1247
	Date: 05/07/2014
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

int s, p, graph[30][30], parent[30][30], n, d;
char ei, ej;

void floyd_warshall () {
	int i, j, k;
	for (i=0; i<30; i++)
		for (j=0; j<30; j++)
			parent[i][j] = i;
	for (k=0; k<26; k++) {
		for (i=0; i<26; i++) {
			for (j=0; j<26; j++) {
				if (graph[i][j] > graph[i][k]+graph[k][j]) {
					graph[i][j] = graph[i][k]+graph[k][j];
					parent[i][j] = parent[k][j];
				}
			}
		}
	}
}

bool first;
void print_path (int i, int j) {
	if (i != j) print_path(i, parent[i][j]);
	if (first) {
		printf("%c", j+'A');
		first = false;
	} else printf(" %c", j+'A');
}

int main() {
	
	int i, j;
	
	scanf("%d %d", &s, &p);
	
	for (i=0; i<30; i++)
		for (j=0; j<30; j++)
		graph[i][j] = INF;
	
	for (i=0; i<p; i++) {
		scanf(" %c %c %d", &ei, &ej, &d);
		graph[ei-'A'][ej-'A'] = d;
		graph[ej-'A'][ei-'A'] = d;
	}
	
	floyd_warshall();
	
	scanf("%d", &n);
	
	for (i=0; i<n; i++) {
		scanf(" %c %c", &ei, &ej);
		first = true;
		print_path(ei-'A', ej-'A');
		printf("\n");
	}
	
	return 0;
}
