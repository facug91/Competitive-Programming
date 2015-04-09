/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2834
        Name: Coprimes III
        Date: 05/03/2015
*/

#include <bits/stdc++.h>
#define EPS (1e-9)
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl;
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

ll n, ans;
vector<ll> f, primes;
bool sieve[32000];

void init() {
	int i, j;
	for (i=3; i<200; i+=2)
		if (!sieve[i])
			for (j=i*i; j<32000; j+=i+i)
				sieve[j] = true;
	primes.push_back(2ll);
	for (i=3; i<32000; i+=2)
		if (!sieve[i])
			primes.push_back((ll)i);
}

void calculate (int idx, ll act, int cant) {
	if (idx == f.size()) {
		if (cant > 0) {
			if (cant % 2 == 0) ans = (ans - ((act*(((n/act-1ll)*(n/act)/2ll) % MOD)) % MOD) + MOD) % MOD;
			else ans = (ans + (act*(((n/act-1ll)*(n/act)/2ll) %MOD) % MOD)) % MOD;
		}
		return;
	}
	calculate(idx+1, act*f[idx], cant+1);
	calculate(idx+1, act, cant);
}

ll solve (ll n) {
	f.clear();
	int i = 0;
	ll aux = n, p = primes[i];
	while (p*p <= n) {
		if (n % p == 0ll) {
			f.push_back(p);
			while (n % p == 0ll) n /= p;
		}
		p = primes[++i];
	}
	if (n > 1 && n != aux) f.push_back(n);
	ans = 0ll;
	calculate(0, 1ll, 0);
	return ans;
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	init();
	while (scanf("%lld", &n) != EOF) printf("%lld\n", solve(n));
	
	return 0;
}
