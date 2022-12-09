/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=1013
        Name: Perfect Pth Powers
        Date: 13/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

ll x, p;
vector<ll> primes;
bool sign;

void init () {
	int i, j;
	bool sieve[47000]; //SQRT(2^31)
	for (i=3; i<220; i+=2) //SQRT(SQRT(2^31))
		if (!sieve[i])
			for (j=i*i; j<47000; j+=i+i)
				sieve[j] = true;
	primes.push_back(2ll);
	for (i=3; i<47000; i+=2)
		if (!sieve[i])
			primes.push_back((ll)i);
}

int gcd (int a, int b) {
	if (a == 0) return b;
	return gcd(b%a, a);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, pi, power, cont;
	ll p;
	
	init();
	while (cin>>x, x) {
		if (x < 0ll) {
			sign = true;
			x *= -1ll;
		} else sign = false;
		power = -1ll;
		pi = 0; p = primes[pi];
		while (p*p <= x) {
			if (x % p == 0ll) {
				cont = 0;
				while (x % p == 0ll) {
					cont++;
					x /= p;
				}
				if (power == -1) power = cont;
				else power = gcd(power, cont);
			}
			p = primes[++pi];
		}
		if (x > 1ll) power = 1;
		if (sign) while (power % 2 == 0) power /= 2;
		cout<<power<<"\n";
	}
	
	return 0;
}
