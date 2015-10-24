/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=524
        Name: Prime Factors
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

ll n, ip, p;
bool sieve[50000];
vector<ll> primes;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(6); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	//cout << std::right << std::setw(13)
	int i, j;
	
	for (i=3; i<230; i+=2) if (!sieve[i])
		for (j=i*i; j<50000; j+=i+i)
			sieve[j] = true;
	primes.push_back(2);
	for (i=3; i<50000; i+=2) if (!sieve[i]) primes.push_back(i);
	while (cin>>n, n) {
		cout<<n<<" =";
		bool first = true;
		if (n < 0) {
			cout<<" -1";
			first = false;
		}
		n = abs(n);
		ip = 0; p = primes[ip];
		while (p*p <= n) {
			while (n % p == 0) {
				if (first) first = false;
				else cout<<" x";
				cout<<" "<<p;
				n /= p;
			}
			p = primes[++ip];
		}
		if (n > 1) {
			if (first) first = false;
			else cout<<" x";
			cout<<" "<<n;
		}
		cout<<endl;
	}
	
	return 0;
}
