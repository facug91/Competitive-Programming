/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1480
        Name: Almost Prime Numbers
        Date: 27/02/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
#define MOD 1000000007ll
#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

ll a, b;
bool sieve[MAXN];
vector<ll> primes;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1;
	
	for (int i=3; i<MAXN; i+=2) sieve[i] = true;
	for (int i=3; i<1005; i++)
		if (sieve[i])
			for (int j=i*i; j<MAXN; j+=i+i)
				sieve[j] = false;
	primes.push_back(-1ll);
	for (ll i=4ll; i<1000000000000ll; i*=2ll) primes.push_back(i);
	for (ll i=3; i<MAXN; i+=2)
		if (sieve[i]) {
			ll j = i*i;
			while (j <= 1000000000000ll) {
				primes.push_back(j);
				j *= i;
			}
		}
	sort(primes.begin(), primes.end());
	cin>>tc;
	while (tc--) {
		cin>>a>>b;
		cout<<distance(lower_bound(primes.begin(), primes.end(), a)-1, upper_bound(primes.begin(), primes.end(), b)-1)<<endl;
	}
	
	return 0;
}
