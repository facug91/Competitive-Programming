/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1431
        Name: Mr. Azad and his Son!!!!!
        Date: 26/10/2015
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

ll n, p, perfect[] = {2, 3, 5, 7, 13, 17, 19, 31}, primes[] = {11, 23, 29};
/*
ll n, p, sumDiv;
bool sieve[1518500500], ans[35];
vector<ll> primes;

ll pow2 (ll n, ll p) {
	ll ans = 1ll;
	for (int i=0; i<p; i++) ans *= n;
	return ans;
}

ll sumOfDivisors (ll n) {
	ll ip = 0, p = primes[ip], ans = 1;
	while (p*p <= n) {
		ll power = 0;
		while (n % p == 0) {
			power++;
			n /= p;
		}
		ans *= ((ll)pow2(p, power + 1) - 1) / (p - 1);
		p = primes[++ip];
	}
	if (n != 1) ans *= ((ll)pow2(n, 2) - 1) / (n - 1);
	return ans;
}

*/
int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j;
	/*
	for (i=3; i<39000; i+=2) if (!sieve[i])
		for (j=i*i; j<1518500500; j+=i+i)
			sieve[j] = true;
	primes.push_back(2);
	for (i=3; i<1518500500; i+=2) if (!sieve[i]) primes.push_back(i);
	*/
	while (cin>>n, n) {
		p = (1ll<<(n-1ll))*((1ll<<n)-1ll);
		/*
		cout<<n<<" ";
		if (sumOfDivisors(p)-p == p) cout<<"Si"<<endl;
		else cout<<"No"<<endl;
		*/
		
		if (binary_search(perfect, perfect+8, n)) cout<<"Perfect: "<<p<<"!"<<endl;
		else if (binary_search(primes, primes+3, n)) cout<<"Given number is prime. But, NO perfect number is available."<<endl;
		else cout<<"Given number is NOT prime! NO perfect number is available."<<endl;
	}
	
	return 0;
}
