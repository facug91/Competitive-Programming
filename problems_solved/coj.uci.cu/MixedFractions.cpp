/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3031
        Name: Mixed Fractions
        Date: 28/12/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000ll
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int num, den;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (scanf("%d %d", &num, &den), num || den)
		printf("%d %d / %d\n", num / den, num % den, den);
	
	return 0;
}
