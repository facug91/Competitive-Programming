/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=635&page=show_problem&problem=2545
	Name: Demanding Dilemma
	Number: 11550
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

int n, m, a, b, sum;
int graph[10][10], edges[10][50], ans;

int main() {
	int t, i, j;
	
	scanf("%d", &t);
	
	while (t--) {
		
		scanf("%d %d", &n, &m);
		
		for (i=0; i<n; i++)
			for (j=0; j<m; j++)
				scanf("%d", &edges[i][j]);
		
		memset(graph, 0, sizeof graph);
		
		ans = true;
		for (j=0; j<m; j++) {
			sum = 0;
			for (i=0; i<n; i++)
				sum += edges[i][j];
			if (sum != 2) {
				ans = false;
				break;
			}
			for (a=0; edges[a][j]==0; a++);
			for (b=a+1; edges[b][j]==0; b++);
			if (graph[a][b]) {
				ans = false;
				break;
			}
			graph[a][b] = true;
			graph[b][a] = true;
		}
		
		if (ans) printf("Yes\n");
		else printf("No\n");
		
	}
	
	return 0;
} 
