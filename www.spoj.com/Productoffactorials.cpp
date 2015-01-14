/*
        By: facug91
        From: http://www.spoj.com/problems/FACTMUL/
        Name: Product of factorials
        Date: 17/12/2014
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
typedef pair<int, int> ii;

ll in, fact[2], n[2], a[2], cant = 2;

pair<ll, ll> extended_euclid (ll a, ll b) {
	ll x = 0, lastx = 1;
	ll y = 1, lasty = 0;
	ll tmp;
	while (b != 0) {
		ll quotient = a/b;
		tmp = a; a = b; b = tmp%b;
		tmp = x; x = lastx - quotient*x; lastx = tmp;
		tmp = y; y = lasty - quotient*y; lasty = tmp;
	}
	return pair<ll, ll>(lastx ,lasty);
}

ll inv (ll a, ll m) {
	pair<ll, ll> res = extended_euclid(a, m);
	return ((res.first % m) + m) % m;
}

ll crt () {
	ll tmp, mod, res;
	int i;
	mod = 1;
	for (i=0; i<cant; i++) {
		mod *= n[i];
	}
	res = 0;
	for (i=0; i<cant; i++) {
		tmp = mod/n[i];
		tmp *= inv(tmp, n[i]);
		res += ((tmp * a[i]) % mod);
	}
	return (res % mod + mod) % mod;
}

int main () {
	ios_base::sync_with_stdio(0);
	
	cin>>in;
	fact[0] = fact[1] = a[0] = a[1] = 1ll;
	for (ll i=2; i<=min(in, 587120ll); i++) {
		fact[0] = (fact[0] * i) % 186583ll;
		a[0] = (fact[0] * a[0]) % 186583ll;
		fact[1] = (fact[1] * i) % 587117ll;
		a[1] = (fact[1] * a[1]) % 587117ll;
		
	}
	n[0] = 186583ll;
	n[1] = 587117ll;
	cout<<crt()<<endl;
	
	return 0;
}
