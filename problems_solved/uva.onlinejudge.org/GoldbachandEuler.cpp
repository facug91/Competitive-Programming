/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1252
        Name: Goldbach and Euler
        Date: 23/10/2015
*/
 
#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, a;
bool sieve[100000100];
vi primes;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	
	sieve[2] = true;
	for (i=3; i<100000100; i+=2) sieve[i] = true;
	for (i=3; i<10010; i+=2) if (sieve[i])
		for (j=i*i; j<100000100; j+=i+i)
			sieve[j] = false;
	primes.push_back(2);
	for (i=3; i<50000100; i+=2) if (sieve[i]) primes.push_back(i);
	while (cin>>n) {
		if (n <= 4) cout<<n<<" is not the sum of two primes!"<<endl;
		else if (n % 2 == 1) {
			if (sieve[n-2]) cout<<n<<" is the sum of 2 and "<<n-2<<"."<<endl;
			else cout<<n<<" is not the sum of two primes!"<<endl;
		} else {
			int ip = lower_bound(primes.begin(), primes.end(), n/2) - primes.begin();
			int p = primes[ip];
			while (p*2 >= n) p = primes[--ip];
			while (ip >= 0 && !sieve[n-p]) p = primes[--ip];
			if (ip >= 0) cout<<n<<" is the sum of "<<p<<" and "<<n-p<<"."<<endl;
			else cout<<n<<" is not the sum of two primes!"<<endl;
		}
	}
	
	return 0;
}
