/*
	By: facug91
	From: http://www.spoj.com/problems/UPDATEIT/
	Name: Update the array !
	Number: 16487
	Date: 20/07/2014
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

int n, u, ft[10005], l, r, v, q, idx;

void adjust (int l, int r, int v) {
	int k;
	for (k=l; k<=n; k+=(k&(-k)))
		ft[k] += v;
	for (k=r+1; k<=n; k+=(k&(-k)))
		ft[k] -= v;
}
int rsq (int b) {
	int sum = 0;
	for (; b; b-=(b&(-b)))
		sum += ft[b];
	return sum;
}

int main() {
	int t, i, j;
	
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &u);
		fill(ft, ft+n+1, 0);
		while (u--) {
			scanf("%d %d %d", &l, &r, &v);
			adjust(l+1, r+1, v);
		}
		scanf("%d", &q);
		while (q--) {
			scanf("%d", &idx);
			printf("%d\n", rsq(idx+1));
		}
	}
	
	return 0;
} 
