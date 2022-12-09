/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=47
        Name: History Grading
        Number: 111
        Date: 20/08/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, event, order[25], seq[25], lis[25];

int LIS () {
	int i, j, mx = 1;
	for (i=1; i<=n; i++) {
		lis[i] = 1;
		for (j=1; j<i; j++) {
			if (seq[j] < seq[i]) {
				if (lis[j]+1 > lis[i])
					lis[i] = lis[j]+1;
			}
		}
		if (lis[i] > mx) mx = lis[i];
	}
	return mx;
}

int main () {
	int TC, i, j;
	
	scanf("%d", &n);
	for (i=1; i<=n; i++) {
		scanf("%d", &order[i]);
	}
	while (scanf("%d", &event) != EOF) {
		seq[event] = order[1];
		for (i=2; i<=n; i++)
			scanf("%d", &event),
			seq[event] = order[i];
		printf("%d\n", LIS());
	}
	
	return 0;
}
