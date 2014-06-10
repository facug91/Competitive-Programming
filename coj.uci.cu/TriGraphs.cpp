/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1448
	Name: Tri Graphs
	Number: 1448
	Date: 10/07/2014
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

int n, graph[100005][3];

int main() {
	
	int t = 1, i;
	
	while (scanf("%d", &n), n) {
		
		for (i=0; i<n; i++)
			scanf("%d %d %d", &graph[i][0], &graph[i][1], &graph[i][2]);
		
		graph[0][0] = INF;
		graph[0][2] += graph[0][1];
		
		for (i=1; i<n; i++) {
			graph[i][0] += min(graph[i-1][0], graph[i-1][1]);
			graph[i][1] += min(min(graph[i-1][0], graph[i-1][1]), min(graph[i-1][2], graph[i][0]));
			graph[i][2] += min(min(graph[i-1][1], graph[i-1][2]), graph[i][1]);
		}
		
		printf("%d. %d\n", t++, graph[n-1][1]);
		
	}
	
	return 0;
} 
