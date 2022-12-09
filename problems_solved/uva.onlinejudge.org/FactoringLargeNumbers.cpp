/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1333
        Name: Factoring Large Numbers
        Date: 10/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

ll n;
vector<ll> primes;
bool sieve[MAXN];

void init () {
	int i, j;
	for (i=3; i<1005; i+=2)
		if (!sieve[i])
			for (j=i*i; j<MAXN; j+=i+i)
				sieve[j] = true;
	primes.push_back(2ll);
	for (i=3; i<MAXN; i+=2)
		if (!sieve[i])
			primes.push_back((ll)i);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i, j;
	
	init();
	while (cin>>n, n >= 0ll) {
		if (n == 0ll || n == 1ll) {
			cout<<"    "<<n<<"\n\n";
			continue;
		}
		i = 0; ll p = primes[i];
		while (i < primes.size() && p*p <= n) {
			while (n % p == 0ll) {
				cout<<"    "<<p<<"\n";
				n /= p;
			}
			i++;
			if (i < primes.size()) p = primes[i];
		}
		if (n > 1ll) cout<<"    "<<n<<"\n";
		cout<<"\n";
	}
	
	return 0;
}
