/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1311
        Name: Unlucky Bird
        Number: 1311
        Date: 16/08/2014
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

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

double v1, v2, v3, a1, a2, d, t, b;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>v1>>v2>>v3>>a1>>a2;
		d = ((v1*v1*0.5)/a1) + ((v2*v2*0.5)/a2);
		t = max((v1/a1), (v2/a2));
		b = v3*t;
		printf("Case %d: %.10lf %.10lf\n", it, d, b);
	}
	
	return 0;
}
