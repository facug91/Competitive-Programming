/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=305
        Name: Combinations
        Number: 369
        Date: 07/10/2014
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

ll comb (ll n, ll m) {
	ll numerator = 1, denominator = 1;
	ll toMul, toDiv;
	ll i, g;
	
	if (m > n/2) m = n - m;
	// usar un m más pequeño
	
	for (i=m; i>0; i--) {
		toMul = n - m + i;
		toDiv = i;
		// siempre dividir antes de multiplicar
		g = __gcd(toMul, toDiv);
		toMul /= g ; toDiv /= g;
		g = __gcd(numerator, toDiv);
		numerator /= g; toDiv /= g;
		g = __gcd(toMul, denominator );
		toMul /= g ; denominator /= g;
		numerator *= toMul;
		denominator *= toDiv;
	}
	
	return numerator / denominator ;
}

ll n, m;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>n>>m, n || m) {
		cout<<n<<" things taken "<<m<<" at a time is "<<comb(n, m)<<" exactly."<<endl;
	}
	
	return 0;
}
