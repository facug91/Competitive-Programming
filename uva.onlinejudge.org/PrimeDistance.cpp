/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1081
        Name: Prime Distance
        Date: 24/10/2015
*/
 
#include <bits/stdc++.h>
#define y1		nd03dnqwuidg1odbnw9uddu0132d
#define clock	asoudh219udhjdgausdhs9udy433
#define left	dfgag34gsfaf342rf23fgwrf42ff
#define middle	lk78k6ujkj76kjk88kkummnhh456
#define right	apidwcojbl213f80sjb3y8efjfas
#define move	df53y5fgsf43fdsfsdtg4j6hfdg4
#define count	nkwdfj111afbjdfsbj32r8yfwejb
#define prev	asdnklgbgbjfasdbhksdva4t9jds
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
//#define MAXN 1000005
 
using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<int, ii> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iii> viii; typedef vector<iiii> viiii;

ll l, r, c2, ic, jc, d2, id, jd, last;
bool sieve[50000];
vector<ll> primes;

ll s, d;
void preCalsd(ll N) {
	s = 0; N--;
	while ((N & 1) == 0) {
		s++;
		N >>= 1LL;
	}
	d = N;
}
ll fastPowMod (ll base, ll num, ll mod) {
	ll ans = 1LL;
	while (num) {
		if (num & 1LL) ans = ans * base % mod;
		base = base * base % mod;
		num >>= 1LL;
	}
	return ans % mod;
}
bool witness(ll a, ll N) {
	ll num = d, m = -1LL;
	for (int i = 0; i < s; i++) {
		num = d * (1LL << i);
		m = fastPowMod(a, num, N);
		if (m == 1LL || m == N-1LL) return false;
	}
	return true;
}
bool miller_rabin(ll N) {
	if(N == 2LL)	return true;
	if(N == 1LL || ((N&1LL) == 0LL))	return false;

	preCalsd(N);
	for(int i = 0; i < 3; i++) //i < 50
	{
		ll a = 2LL + rand() % (N-2LL);
		if(witness(a, N)) return false;
	}
	return true;
}

bool isPrime (ll x) {
	return miller_rabin(x);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	
	for (int i=0; i<50000; i++) sieve[i] = true;
	for (int i=3; i<250; i+=2) if (sieve[i])
		for (int j=i*i; j<50000; j+=i+i)
			sieve[j] = false;
	primes.push_back(2);
	for (int i=3; i<50000; i+=2) if (sieve[i]) primes.push_back(i);
	while (cin>>l>>r) {
		c2 = INF; d2 = -1ll; last = -1ll;
		if (l <= 2ll) {
			last = 2ll;
			l = 3ll;
		}
		if (l % 2 == 0) l++;
		for (ll i=l; i<=r; i+=2ll) {
			if (isPrime(i)) {
				if (last == -1ll) last = i;
				else {
					if (c2 > i-last) {
						c2 = i-last;
						ic = last;
						jc = i;
					}
					if (d2 < i-last) {
						d2 = i-last;
						id = last;
						jd = i;
					}
					last = i;
				}
			}
		}
		if (c2 == INF) cout<<"There are no adjacent primes."<<endl;
		else cout<<ic<<","<<jc<<" are closest, "<<id<<","<<jd<<" are most distant."<<endl;
	}
	
	return 0;
}
