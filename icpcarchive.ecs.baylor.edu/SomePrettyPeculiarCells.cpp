/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=627&page=show_problem&problem=4420
        Name: Some Pretty Peculiar Cells
        Date: 06/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl;
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

vector<ll> primes;

void init () {
	int i, j;
	bool sieve[40005];
	memset(sieve, -1, sizeof sieve);
	for (i=3; i<205; i+=2)
		if (sieve[i])
			for (j=i*i; j<40005; j+=i+i)
				sieve[j] = false;
	primes.push_back(2ll);
	for (i=3; i<40005; i+=2)
		if (sieve[i])
			primes.push_back((ll)i);
}

ll fast_mod_pow (ll b, ll e, ll m) {
	if (e == 0ll) return 1ll;
	ll ans = fast_mod_pow(b, e/2ll, m);
	ans = (ans * ans) % m;
	if (e % 2ll == 1ll) ans = (ans * b) % m;
	return ans;
}

ll phi (ll n) {
	int i = 0;
	ll p = primes[i], ans = n;
	while (p*p <= n) {
		if (n % p == 0ll) ans -= ans / p;
		while (n % p == 0ll) n /= p;
		p = primes[++i];
	}
	if (n != 1ll) ans -= ans / n;
	return ans;
}

ll min_cycle (ll e, ll a, ll m) {
	vector<ll> divs;
	ll i = 2ll;
	divs.push_back(e);
	while (i*i <= e) {
		if (e % i == 0ll) {
			if ((fast_mod_pow(2ll, i, m)*a)%m == a) return i;
			divs.push_back(e/i);
		}
		i++;
	}
	for (int j=divs.size()-1; j>=0; j--)
		if ((fast_mod_pow(2ll, divs[j], m)*a)%m == a) return divs[j];
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC;
	ll x, y, a, m, e;
	
	init();
	cin>>TC;
	while (TC--) {
		cin>>x>>y>>a;
		m = x * y;
		ll e = phi(m);
		if ((fast_mod_pow(2ll, e, m)*a)%m == a) cout<<min_cycle(e, a, m)<<endl;
		else cout<<"IMPOSSIBLE!"<<endl;
	}
	
	return 0;
}
