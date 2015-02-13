/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2562
        Name: Brains in Action
        Date: 01/02/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n;
bool sieve[1000010];
vector<int> primes;

void init () {
	int i, j;
	memset(sieve, -1, sizeof sieve);
	for (i=3; i<1010; i+=2)
		if (sieve[i])
			for (j=i*i; j<1000010; j+=i+i)
				sieve[j] = false;
	primes.push_back(2);
	for (i=3; i<1000010; i+=2)
		if (sieve[i])
			primes.push_back(i);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	init();
	while (cin>>n) {
		i = 0; int p = primes[i];
		while (p*p <= n) {
			j = 0;
			while (n % p == 0) {
				n /= p;
				j++;
			}
			if (j) cout<<"("<<p<<"("<<j<<"))";
			p = primes[++i];
		}
		if (n != 1) cout<<"("<<n<<"(1))";
		cout<<endl;
	}
	
	return 0;
}
