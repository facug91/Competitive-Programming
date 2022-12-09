/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2987
        Name: N + NOD (N)
        Date: 01/04/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int a, b;
vi primes, DP;
vi::iterator l, r;

void calculate_primes () {
	bool sieve[1005];
	memset(sieve, -1, sizeof sieve);
	for (int i=3; i<400; i+=2)
		if (sieve[i])
			for (int j=i*i; j<1005; j+=i+i)
				sieve[j] = false;
	primes.push_back(2);
	for (int i=3; i<1005; i+=2)
		if (sieve[i])
			primes.push_back(i);
}

int number_of_divisors (int n) {
	int pi = 0, p = primes[pi], ans = 1;
	while (p*p <= n) {
		int power = 0;
		while (n % p == 0) {
			n /= p;
			power++;
		}
		ans *= (power+1);
		p = primes[++pi];
	}
	if (n != 1) ans *= 2;
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i, j;
	
	calculate_primes();
	DP.push_back(0);
	DP.push_back(1);
	for (i=2; DP[i-1]<=1000050; i++) DP.push_back(DP[i-1] + number_of_divisors(DP[i-1]));
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>a>>b;
		l = lower_bound(DP.begin(), DP.end(), a); l--;
		r = upper_bound(DP.begin(), DP.end(), b); r--;
		cout<<"Case "<<it<<": "<<distance(l, r)<<"\n";
	}
	
	return 0;
}
