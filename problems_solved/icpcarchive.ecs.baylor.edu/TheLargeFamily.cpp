/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4416
        Name: The Large Family
        Date: 13/02/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, p, c;

int main () {
	//ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j;
	
	while (scanf("%d", &n), n) {
		n *= 2;
		p = c = n / 7;
		n %= 7;
		if (n >= 5) c++, n -= 5;
		else if (n >= 2) p++, n -= 2;
		printf("%d.%d %d.%d %d.%d %d.%d\n", n/2, (n%2)?5:0, p/2, (p%2)?5:0, p/2, (p%2)?5:0, c/2, (c%2)?5:0);
	}
	
	return 0;
}
