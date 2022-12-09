/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1080
        Name: Factovisors
        Number: 10139
        Date: 04/10/2014
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

int n, m, primes[5000];
bool sieve[24000];
vector<ii> factors;


void calc_primes () {
	int P_idx = 0, i, j;
	memset(sieve, -1, sizeof sieve);
	primes[P_idx++] = 2;
	for (i=3; i<230; i+=2) {
		if (sieve[i/2]) {
			for (j=i*i; j<48000; j+=(i<<1)) {
				sieve[j/2] = false;
			}
		}
	}
	for (i=3; i<48000; i+=2) {
		if (sieve[i/2]) {
			primes[P_idx++] = i;
		}
	}
}

void prime_factors (int n) {
	factors.clear();
	int PF_idx = 0, PF = primes[0];
	while (PF*PF <= n) {
		if (n % PF == 0) {
			factors.push_back(ii(PF, 1));
			n /= PF;
		}
		while (n % PF == 0) {
			factors.back().second++;
			n /= PF;
		}
		PF = primes[PF_idx++];
	}
	if (n != 1) factors.push_back(ii(n, 1));
}

bool check () {
	int i, j, cant, f, auxn;
	for (i=0; i<(int)factors.size(); i++) {
		cant = 0; f = factors[i].first;	auxn = n;
		while (auxn >= f) {
			cant += (auxn / f);
			auxn /= f;
		}
		if (cant < factors[i].second) return false;
	}
	return true;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	calc_primes();
	while (cin>>n>>m) {
		prime_factors(m);
		if (check()) cout<<m<<" divides "<<n<<"!"<<endl;
		else cout<<m<<" does not divide "<<n<<"!"<<endl;
	}
	
	return 0;
}

