/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1035
        Name: Intelligent Factorial Factorization
        Date: 12/05/2015
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
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, p, alfa;
vi primes;
bool sieve[250];

void init () {
	int i, j;
	memset(sieve, -1, sizeof sieve);
	for (i=3; i<50; i+=2)
		if (sieve[i])
			for (j=i*i; j<250; j+=i+i)
				sieve[j] = false;
	primes.push_back(2);
	for (i=3; i<250; i+=2)
		if (sieve[i])
			primes.push_back(i);
}

int main () {
	int tc, i, j;
	
	init();
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n;
		cout<<"Case "<<it<<": "<<n<<" =";
		bool first = true;
		for (i=0; primes[i]<=n; i++) {
			alfa = 0; p = primes[i];
			while (p <= n) {
				alfa += (n/p);
				p *= primes[i];
			}
			if (p != primes[i]) {
				if (first) first = false;
				else cout<<" *";
				cout<<" "<<primes[i]<<" ("<<alfa<<")";
			}
		}
		cout<<"\n";
	}
	
	return 0;
}
