/*
        By: facug91
        From: http://lightoj.com/volume_showproblem.php?problem=1178
        Name: Trapezium
        Number: 1178
        Date: 08/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 131071
//#define MAXN 10000010

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

double a, b, c, d;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>a>>b>>c>>d;
		if (a > c) {
			double tmp = a;
			a = c;
			c = tmp;
		}
		double sp = (b+d+c-a)*0.5;
		double area_t = sqrt(sp*(sp-b)*(sp-d)*(sp-(c-a)));
		printf("Case %d: %.6lf\n", it, ((2.0*area_t)/(c-a))*a+area_t);
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
