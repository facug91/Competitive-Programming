/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1133
	Name: Array Simulation
	Number: 1133
	Date: 25/07/2014
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
//const double PI = 2*acos(0.0);

#define INF 1000000000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int n, m, a[105], x, y;
char op;

int main () {
    int t, i, j;
    
    scanf("%d", &t);
    for (int it=1; it<=t; it++) {
		scanf("%d %d", &n, &m);
		for (i=0; i<n; i++)
			scanf("%d", a+i);
		for (i=0; i<m; i++) {
			scanf(" %c", &op);
			if (op == 'S') {
				scanf("%d", &x);
				for (j=0; j<n; j++)
					a[j] += x;
			} else if (op == 'M') {
				scanf("%d", &x);
				for (j=0; j<n; j++)
					a[j] *= x;
			} else if (op == 'D') {
				scanf("%d", &x);
				for (j=0; j<n; j++)
					a[j] /= x;
			} else if (op == 'R') {
				reverse(a, a+n);
			} else {
				scanf("%d", &x);
				scanf("%d", &y);
				swap(a[x], a[y]);
			}
		}
		printf("Case %d:\n", it);
		printf("%d", a[0]);
		for (i=1; i<n; i++)
			printf(" %d", a[i]);
		printf("\n");
	}
    
    return 0;
}
