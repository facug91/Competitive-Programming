/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1621
        Name: LCM
        Number: 10680
        Date: 22/09/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
#define MAXN 1000010

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n;
bool sieve[MAXN];
vector<int> primes;
vector<double> lprimes;
double l, l2, l5;

void init () {
	int i, j;
	memset(sieve, -1, sizeof sieve);
	for (i=3; i<1005; i+=2)
		if (sieve[i])
			for (j=i*3; j<MAXN; j+=(i*2))
				sieve[j] = false;
	primes.push_back(3);
	lprimes.push_back(log(3));
	for (i=7; i<MAXN; i+=2) {
		if (sieve[i]) {
			primes.push_back(i);
			lprimes.push_back(log(i));
		}
	}
	l2 = log(2);
	l5 = log(5);
}

int mod_pow (int n, int p) {
	int i, ans = 1;
	for (i=0; i<p; i++)
		ans = (ans * n) % 10;
	return ans;
}

int calc () {
	if (n == 1) return 1;
	int i, j, r;
	int ans = 1;
	l = log(n);
	if (n >= 5) ans = (ans * (1<<(((int)floor(l/l2))-((int)floor(l/l5))))) % 10;
	else ans = (ans * ((n/2) * 2)) % 10;
	r = (int)ceil(sqrt(n)) + 1;
	for (i=0; primes[i]<=r; i++)
		ans = (ans * mod_pow(primes[i], (int)floor(l/lprimes[i]))) % 10;
	for (; primes[i]<=n; i++)
		ans = (ans * primes[i]) % 10;
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	init();
	while (cin>>n, n)
		cout<<calc()<<endl;
	
	return 0;
}

