/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1261
	Name: K-SAT Problem
	Number: 1261
	Date: 26/07/2014
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
const double PI = 2.0*acos(0.0);

#define INF 1000000000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int n, m, k, wish[35][35], p, sol[35];

bool is_valid_for (int idx) {
	int i, j;
	for (i=0; i<k; i++)
		if (wish[idx][i] > 0) {
			for (j=0; j<p; j++)
				if (wish[idx][i] == sol[j])
					return true;
		} else {
			bool find = false;
			for (j=0; j<p; j++)
				if (-wish[idx][i] == sol[j]) {
					find = true;
					break;
				}
			if (!find) return true;
		}
	return false;
}

bool is_valid () {
	for (int i=0; i<n; i++) 
		if (!is_valid_for(i)) return false;
	return true;
}

int main () {
	int t, i, j;
	
	scanf("%d", &t);
	for (int it=1; it<=t; it++) {
		scanf("%d %d %d", &n, &m, &k);
		for (i=0; i<n; i++)
			for (j=0; j<k; j++)
				scanf("%d", &wish[i][j]);
		scanf("%d", &p);
		for (i=0; i<p; i++)
			scanf("%d", &sol[i]);
		if (is_valid()) printf("Case %d: Yes\n", it);
		else printf("Case %d: No\n", it);
	}
	
	return 0;
}
