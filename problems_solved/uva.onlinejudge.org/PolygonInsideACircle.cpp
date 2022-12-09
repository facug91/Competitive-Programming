/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1373
        Name: Polygon Inside A Circle
        Date: 11/11/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

double r, n, side, perimeter, apothem;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>r>>n)
		printf("%.03lf\n", n*r*r*sin(2.0*PI/n)*0.5);
	
	return 0;
}
