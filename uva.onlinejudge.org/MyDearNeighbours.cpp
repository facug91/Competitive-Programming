/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1869
	Name: My Dear Neighbours
	Number: 10928
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

int p, n[1010], ans;
char s[10000], *pc = new char[10];

int main() {
	int t, i, j;
	
	scanf("%d", &t);
	
	while (t--) {
		scanf("%d", &p);
		getchar();
		
		memset(n, 0, sizeof n);
		ans = INF;
		for (i=1; i<=p; i++) {
			gets(s);
			if (s[0] != 0) {
				pc = strtok(s, " ");
				while (pc != NULL) {
					n[i]++;
					pc = strtok(NULL, " ");
				}
			}
			if (n[i] < ans) ans = n[i];
		}
		
		for (i=1; n[i]!=ans; i++);
		printf("%d", i);
		for (++i; i<=p; i++)
			if (n[i]==ans)
				printf(" %d", i);
		printf("\n");
		
	}
	
	return 0;
} 
