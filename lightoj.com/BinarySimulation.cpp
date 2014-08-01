/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1080
	Name: Binary Simulation
	Number: 1080
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

int n, ft[100005], q, x, y;
char s[100005], op;

int rsq (int b) {
	int sum = 0;
	for (; b; b -= (b&(-b)))
		sum += ft[b];
	return sum;
}

void adjust (int k, int v) {
	for (; k<=n; k+=(k&(-k)))
		ft[k] += v;
}

void adjust_range (int i, int j) {
	int k;
	for (k=i; k<=n; k+=(k&(-k)))
		ft[k]++;
	for (k=j+1; k<=n; k+=(k&(-k)))
		ft[k]--;
}

int main() {
	int t, i, j;
	
	scanf("%d", &t);
	
	for (int it=1; it<=t; it++) {
		scanf("%s", s);
		n = strlen(s);
		memset(ft, 0, sizeof ft);
		
		bool on = false;
		for (i=1; i<=n; i++) {
			if (on) {
				if (s[i-1] == '0') {
					adjust(i, -1);
					on = false;
				}
			} else {
				if (s[i-1] == '1') {
					adjust(i, 1);
					on = true;
				}
			}
		}
		
		scanf("%d", &q);
		printf("Case %d:\n", it);
		for (i=0; i<q; i++) {
			scanf(" %c %d", &op, &x);
			if (op == 'Q') printf("%d\n", (rsq(x))%2);
			else {
				scanf("%d", &y);
				adjust_range(x, y);
			}
		}
		
	}
	
	return 0;
} 
