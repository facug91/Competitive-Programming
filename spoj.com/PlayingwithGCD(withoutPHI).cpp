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

void search (int idx, int act, int cant) {
	if (act * primes[idx] > 50000) {
		add[act] = (cant % 2 == 1) ? 1 : -1;
		return;
	}
	search(idx+1, act, cant);
	search(idx+1, act*primes[idx], cant+1);
}

void init () {
	int i, j, k, a;
	for (i=3; i<100005; i+=2) criba[i] = true;
	for (i=3; i<320; i+=2)
		if (criba[i])
			for (j=i*i; j<100005; j+=i+i)
				criba[j] = false;
	memset(add, 0, sizeof add);
	primes.push_back(2);
	add[2] = 1;
	for (i=3; i<100005; i+=2) {
		if (criba[i]) {
			primes.push_back(i);
			add[i] = 1;
		}
	}
	for (i=0; primes[i]<225; i++)
		for (j=i+1; primes[i]*primes[j]<=50000; j++)
			search(j+1, primes[i]*primes[j], 2);
	rsq[0] = rsq[1] = 0;
	for (i=2; i<100005; i++)
		rsq[i] = 1;
	for (i=2; i<=50000; i++) {
		if (add[i] != 0) {
			k = add[i]; a = add[i];
			for (j=i+i; j<100005; j+=i) {
				rsq[j] += k;
				k += a;
			}
		}
	}
	for (i=2; i<100005; i++)
		rsq[i] += rsq[i-1];
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
