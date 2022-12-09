/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=931
	Name: Diving for Gold
	Number: 990
	Date: 02/07/2014
	Using: Bottom-Up approach
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

int t, w, n, deaph[35], gold[35], DP[35][1005];
stack<pair<int, int> > st;

int main() {
	
	int i, j;
	bool first = true;
	
	while (scanf("%d %d", &t, &w) != EOF) {
		
		if (first) first = false;
		else printf("\n");
		
		scanf("%d", &n);
		
		for (i=1; i<=n; i++) {
			scanf("%d %d", deaph+i, gold+i);
			deaph[i] *= w*3;
		}
		
		for (i=0; i<n; i++) DP[i][0] = 0;
		for (i=0; i<t; i++) DP[0][i] = 0;
		
		for (i=1; i<=n; i++) {
			for (j=1; j<=t; j++) {
				if (deaph[i] > j) DP[i][j] = DP[i-1][j];
				else DP[i][j] = max(DP[i-1][j], DP[i-1][j-deaph[i]] + gold[i]);
			}
		}
		
		printf("%d\n", DP[n][t]);
		int cont = 0;
		for (i=n, j=t; i>0; i--) {
			if (DP[i][j] != DP[i-1][j]) {
				st.push(make_pair(deaph[i]/w/3,gold[i]));
				cont++;
				j -= deaph[i];
			}
		}
		printf("%d\n", cont);
		for (i=0; i<cont; i++) {
			printf("%d %d\n", st.top().first, st.top().second);
			st.pop();
		}
		
	}
	
	return 0;
}
