/*
        By: facug91
        From: http://lightoj.com/volume_showproblem.php?problem=1077
        Name: How Many Points?
        Number: 1077
        Date: 09/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 131071
//#define MAXN 10000010

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

ll _x0, _y0, _x1, _y1;

ll gcd (ll a, ll b) {
	if (a == 0ll) return b;
	return gcd(b%a, a);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>_x0>>_y0>>_x1>>_y1;
		cout<<"Case "<<it<<": "<<gcd(llabs(_x0-_x1), llabs(_y0-_y1))+1<<endl;
	}
	
	return 0;
}
