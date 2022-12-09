/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1067
        Name: Combinations
        Date: 12/05/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000003ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;

ll n, k, fact[1000005];

pair<ll, ll> extended_euclid (ll a, ll b) {
	ll x = 0ll, lastx = 1ll;
	ll y = 1ll, lasty = 0ll;
	ll tmp;
	while (b != 0ll) {
		ll quotient = a/b;
		tmp = a; a = b; b = tmp%b;
		tmp = x; x = lastx - quotient*x; lastx = tmp;
		tmp = y; y = lasty - quotient*y; lasty = tmp;
	}
	return make_pair(lastx ,lasty);
}

ll inv (ll a, ll m) {
	pair<ll, ll> res = extended_euclid(a, m);
	return ((res.first % m) + m) % m;
}

int main () {
	int tc, i, j;
	
	fact[0] = 1ll;
	for (i=1; i<1000005; i++) fact[i] = (fact[i-1] * (ll)i) % MOD;
	scanf("%d", &tc);
	for (int it=1; it<=tc; it++) {
		scanf("%lld %lld", &n, &k);
		printf("Case %d: %lld\n", it, (fact[n]*inv(fact[k]*fact[n-k], MOD))%MOD);
	}
	
	return 0;
}
