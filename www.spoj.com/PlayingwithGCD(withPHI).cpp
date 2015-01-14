/*
        By: facug91
        From: http://www.spoj.com/problems/NAJPWG/
        Name: Playing with GCD
        Date: 14/11/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, add[100005], rsq[100005];
bool criba[100005];
vector<int> primes;

int phi (int n) {
	int ans = n;
	for (int i=0; primes[i]*primes[i]<=n; i++) {
		if (n % primes[i] == 0) ans -= (ans/primes[i]);
		while (n % primes[i] == 0) n /= primes[i];
	}
	if (n > 1) ans -= (ans/n);
	return ans;
}

void init () {
	int i, j, k, a;
	for (i=3; i<100005; i+=2) criba[i] = true;
	for (i=3; i<320; i+=2)
		if (criba[i])
			for (j=i*i; j<100005; j+=(i+i))
				criba[j] = false;
	primes.push_back(2);
	for (i=3; i<100005; i+=2)
		if (criba[i])
			primes.push_back(i);
	rsq[0] = rsq[1] = 0;
	for (i=2; i<100005; i++)
		rsq[i] = (i - phi(i)) + rsq[i-1];
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	init();
	scanf("%d", &TC);
	for (int it=1; it<=TC; it++) {
		scanf("%d", &n);
		printf("Case %d: %d\n", it, rsq[n]);
	}
	
	return 0;
}
