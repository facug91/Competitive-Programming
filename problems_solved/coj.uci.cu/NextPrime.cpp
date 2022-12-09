/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2272
        Name: Next Prime
        Date: 03/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
#define MAXN 4000000000ll
#define SQMAXN 64000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

vector<ll> primes;

void init () {
	int i, j;
	bool sieve[SQMAXN];
	memset(sieve, -1, sizeof sieve);
	for (i=3; i*i<SQMAXN; i+=2)
		if (sieve[i])
			for (j=i*i; j<SQMAXN; j+=i+i)
				sieve[j] = false;
	primes.push_back(2ll);
	for (i=3; i<SQMAXN; i+=2)
		if (sieve[i])
			primes.push_back((ll)i);
}

bool is_prime (ll n) {
	for (int i=0; primes[i]*primes[i]<=n; i++)
		if (n % primes[i] == 0ll)
			return false;
	return true;
}

ll next_prime (ll n) {
	while (true) {
		if (is_prime(n)) break;
		n++;
	}
	return n;
}

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j, l;
	ll n;
	
	init();
	cin>>TC;
	while (TC--) {
		cin>>n;
		if (n <= 1ll) n = 2ll;
		cout<<next_prime(n)<<endl;
	}
	
	return 0;
}
