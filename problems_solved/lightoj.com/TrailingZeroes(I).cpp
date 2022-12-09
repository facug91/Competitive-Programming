/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1028
	Name: Trailing Zeroes (I)
	Date: 06/07/2016
*/

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define prev bjasdbi132ge79qwgdi
#define next usayhkdgisaydgiy212
#define move sdjifha978dyd9sag89
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 100000007
//#define MAXN 10000005

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, int> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; //insert, find_by_order, order_of_key, erase

ll n, primes[80000]; // There are 78.000 primes smaller than 10^6 aprox.
bool sieve[1000005];

ll divisors () {
	ll ans = 1, ip = 0, p = primes[ip], cnt;
	while (p*p <= n) {
		if (n % p == 0) {
			cnt = 0;
			while (n % p == 0) {
				n /= p;
				cnt++;
			}
			ans *= (cnt+1);
		}
		p = primes[++ip];
	}
	if (n > 1) ans *= 2ll;
	return ans;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
	
	for (i=3; i<1005; i+=2) if (!sieve[i])
		for (j=i*i; j<1000005; j += i+i)
			sieve[j] = true;
	int np = 0;
	primes[np++] = 2;
	for (i=3; i<1000005; i+=2) if (!sieve[i]) primes[np++] = i;
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n;
		cout<<"Case "<<it<<": "<<divisors()-1<<endl;
	}
	
	return 0;
}
