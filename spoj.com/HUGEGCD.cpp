/*
        By: facug91
        From: http://www.spoj.com/problems/HG/
        Name: HUGE GCD
        Date: 25/11/2014
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

int n, m, aux;
ll ans;
vector<int> primes, a, factora, b, factorb;
bool sieve[31625], big;

void init () {
	int i, j;
	for (i=3; i<31625; i+=2)
		sieve[i] = true;
	for (i=3; i<180; i+=2)
		if (sieve[i])
			for (j=i*i; j<31625; j+=i+i)
				sieve[j] = false;
	primes.push_back(2);
	for (i=3; i<31625; i+=2)
		if (sieve[i])
			primes.push_back(i);
}

void make_factors (vector<int> &origin, vector<int> &dest) {
	int i, j, n, p, pi;
	for (i=0; i<(int)origin.size(); i++) {
		n = origin[i]; p = primes[pi = 0];
		while (p*p <= n) {
			while (n % p == 0) {
				dest.push_back(p);
				n /= p;
			}
			p = primes[pi++];
		}
		if (n != 1) dest.push_back(n);
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	init();
	
	cin>>n;
	for (i=0; i<n; i++) {
		cin>>aux;
		a.push_back(aux);
	}
	make_factors(a, factora);
	sort(factora.begin(), factora.end());
	
	cin>>m;
	for (i=0; i<m; i++) {
		cin>>aux;
		b.push_back(aux);
	}
	make_factors(b, factorb);
	sort(factorb.begin(), factorb.end());
	
	/*cerr<<endl;
	for (i=0; i<(int)factora.size(); i++)
		cerr<<factora[i]<<" ";
	cerr<<endl<<endl;
	for (i=0; i<(int)factorb.size(); i++)
		cerr<<factorb[i]<<" ";
	cerr<<endl<<endl;*/
	
	ans = 1; i = j = 0;
	big = false;
	while (i < (int)factora.size() && j < (int)factorb.size()) {
		if (factora[i] == factorb[j]) {
			ans *= (ll)factora[i];
			i++; j++;
			if (ans >= 1000000000ll) {
				big = true;
				ans %= 1000000000ll;
			}
		} else if (factora[i] < factorb[j]) {
			i++;
		} else {
			j++;
		}
	}
	
	if (big) printf("%09lld\n", ans);
	else printf("%lld\n", ans);
	
	
	
	
	
	
	
	return 0;
}
