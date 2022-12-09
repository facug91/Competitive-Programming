/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1836
	Name: Matrix Transpose
	Number: 10895
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
//
using namespace std;

int m, n, r, a, row[10010];
vector<int> matrix[10010], pos[10010];

int main() {
	int i, j;
	
	while (scanf("%d %d", &m, &n) != EOF) {
		
		for (i=1; i<=n; i++) {
			matrix[i].clear();
			pos[i].clear();
		}
		
		for (i=1; i<=m; i++) {
			scanf("%d", &r);
			for (j=0; j<r; j++)
				scanf("%d", row+j);
			for (j=0; j<r; j++) {
				scanf("%d", &a);
				matrix[row[j]].push_back(a);
				pos[row[j]].push_back(i);
			}
		}
		
		printf("%d %d\n", n, m);
		for (i=1; i<=n; i++) {
			if (matrix[i].size() == 0) printf("0\n\n");
			else {
				printf("%d", matrix[i].size());
				for (j=0; j<matrix[i].size(); j++)
					printf(" %d", pos[i][j]);
				printf("\n");
				printf("%d", matrix[i][0]);
				for (j=1; j<matrix[i].size(); j++)
					printf(" %d", matrix[i][j]);
				printf("\n");
			}
		}
		
	}
	
	return 0;
} 
