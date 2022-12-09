/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1319
        Name: Monkey Tradition
        Number: 1319
        Date: 17/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007
//#define MAXN 3000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n;
ll p[15], r[15];

pair<ll, ll> extended_euclid (ll a, ll b) {
	ll x = 0ll, lastx = 1ll;
	ll y = 1ll, lasty = 0ll;
	ll tmp;
	while (b != 0ll) {
		ll quotient = a/b;
		tmp = a; a = b; b = tmp % b;
		tmp = x; x = lastx - quotient * x; lastx = tmp;
		tmp = y; y = lasty - quotient * y; lasty = tmp;
	}
	return pair<ll, ll>(lastx, lasty);
}
ll inv (ll a, ll m) {
	pair<ll, ll> res = extended_euclid(a, m);
	return ((res.first % m) + m) % m; 
}
ll crt () {
	int i;
	ll tmp, mod, res;
	mod = 1ll;
	for (i=0; i<n; i++) {
		mod *= p[i];
	}
	res = 0ll;
	for (i=0; i<n; i++) {
		tmp = mod / p[i];
		tmp *= inv(tmp, p[i]);
		res += ((tmp * r[i]) % mod);
	}
	return (res % mod + mod) % mod;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>n;
		for (i=0; i<n; i++) {
			cin>>p[i]>>r[i];
		}
		cout<<"Case "<<it<<": "<<crt()<<endl;
	}
	
	return 0;
}
