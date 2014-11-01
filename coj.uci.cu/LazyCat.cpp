/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2842
        Name: Lazy Cat
        Date: 31/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int q, l, r;
bitset<10000050> sieve;
vector<int> primes;
int num[10];

bool is_palindrome (int n) {
	int i = 0, j;
	while (n) {
		num[i++] = n%10;
		n /= 10;
	}
	for (j=0, i--; j<i; j++, i--) 
		if (num[j] != num[i])
			return false;
	return true;
}

void init () {
	int i, j;
	for (i=3; i<10000050; i+=2)
		sieve[i] = 1;
	for (i=3; i<3170; i+=2)
		if (sieve[i])
			for (j=i*i; j<10000050; j+=(i+i))
				sieve[j] = 0;
	primes.push_back(2);
	for (i=3; i<10000050; i+=2)
		if (sieve[i] && is_palindrome(i))
			primes.push_back(i);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	init();
	cin>>q;
	while (q--) {
		cin>>l>>r;
		cout<<distance(lower_bound(primes.begin(), primes.end(), l), upper_bound(primes.begin(), primes.end(), r))<<endl;
	}
	
	return 0;
}
