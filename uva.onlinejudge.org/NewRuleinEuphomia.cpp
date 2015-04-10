/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1683
        Name: New Rule in Euphomia
        Date: 01/04/2015
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

int n;
ll ans;
bool sieve[1000005];
vi primes;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC = 1, i, j;
	
	for (i=3; i<1005; i+=2)
		if (!sieve[i])
			for (j=i*i; j<1000005; j+=i+i)
				sieve[j] = true;
	primes.push_back(2);
	for (i=3; i<1000005; i+=2)
		if (!sieve[i])
			primes.push_back(i);
	while (cin>>n, n) {
		i = 0; j = 1; ans = 0;
		while (primes[j]+2 <= n) {
			while (primes[i]+primes[j] > n) i--;
			ans += i+1;
			j++; i++;
		}
		cout<<"Case "<<TC++<<": "<<ans<<"\n";
	}
	
	return 0;
}
