/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=230
        Name: Divisors
        Date: 24/10/2015
*/
 
#include <bits/stdc++.h>
#define y1		nd03dnqwuidg1odbnw9uddu0132d
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
typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iii> viii; typedef vector<iiii> viiii;

int l, r;
bool sieve[32000];
vi primes;

int number_of_divisors (int x) {
	int ip = 0, p = primes[ip], cnt = 1, aux;
	while (p*p <= x) {
		if (x % p == 0) {
			aux = 1;
			while (x % p == 0) {
				x /= p;
				aux++;
			}
			cnt *= aux;
		}
		p = primes[++ip];
	}
	if (x > 1) cnt *= 2;
	return cnt;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(6); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	//cout << std::right << std::setw(13)
	int tc, i, j;
	
	for (i=3; i<180; i+=2) if (!sieve[i])
		for (j=i*i; j<32000; j+=i+i)
			sieve[j] = true;
	primes.push_back(2);
	for (i=3; i<32000; i+=2) if (!sieve[i]) primes.push_back(i);
	cin>>tc;
	while (tc--) {
		cin>>l>>r;
		int prime, divisors = -1, aux;
		for (i=l; i<=r; i++) {
			aux = number_of_divisors(i);
			if (aux > divisors) {
				divisors = aux;
				prime = i;
			}
		}
		cout<<"Between "<<l<<" and "<<r<<", "<<prime<<" has a maximum of "<<divisors<<" divisors."<<endl;
	}
	
	return 0;
}
