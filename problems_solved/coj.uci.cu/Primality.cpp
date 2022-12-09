/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2019
        Name: Primality
        Date: 07/04/2015
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

int n, arr[15], size;
bool sieve[10500];
vi primes;
set<int> ans;

bool is_prime (int n) {
	if (n == 1) return false;
	int pi = 0, p = primes[pi];
	while (p*p <= n) {
		if (n % p == 0) return false;
		p = primes[++pi];
	}
	return true;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' ');
	int i, j;
	
	for (i=3; i<150; i+=2)
		if (!sieve[i])
			for (j=i*i; j<10500; j+=i+i)
				sieve[j] = true;
	primes.push_back(2);
	for (i=3; i<10500; i+=2)
		if (!sieve[i])
			primes.push_back(i);
	cin>>n;
	size = 0;
	while (n) {
		arr[size++] = n % 10;
		n /= 10;
	}
	sort(arr, arr+size);
	do {
		n = 0;
		for (i=0; i<size; i++) n = n * 10 + arr[i];
		if (is_prime(n)) ans.insert(n);
		
	} while (next_permutation(arr, arr+size));
	cout<<ans.size()<<"\n";
	
	return 0;
}
