/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3223
        Name: Sum of Factors
        Date: 05/04/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

bool sieve[MAXN];
ll n;
vector<ll> primes;

ll sum_div (ll n) {
	ll pi = 0ll, p = primes[pi], ans = 1ll;
	while (p * p <= n) {
		ll power = 0ll;
		while (n % p == 0ll) {
			n /= p;
			power++;
		}
		ans *= ((ll)pow((double)p, power + 1.0) - 1ll) / (p - 1ll);
		p = primes[++pi];
	}
	if (n != 1ll) ans *= (n*n - 1ll) / (n - 1ll);
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i, j;
	
	memset(sieve, 0, sizeof sieve);
	for (i=3; i<1005; i+=2)
		if (!sieve[i])
			for (j=i*i; j<MAXN; j+=i+i)
				sieve[j] = true;
	primes.push_back(2ll);
	for (i=3; i<MAXN; i+=2)
		if (!sieve[i]) primes.push_back((ll)i);
	cin>>TC;
	while (TC--) {
		cin>>n;
		cout<<sum_div(n)<<"\n";
	}
	
	return 0;
}
