/*
        By: facug91
        From: http://coj.uci.cu/24h/bestsolutions.xhtml?pid=2558
        Name: Horace and his Primes
        Date: 09/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl;
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int sieve[1000005], order[1000005], a, b, k, RSQ[13][1000005];

void init () {
	int i, j;
	memset(sieve, 0, sizeof sieve);
	memset(order, 0, sizeof order);
	for (i=2; i<1000005; i++) {
		if (sieve[i] == 0) {
			order[i] = 1;
			for (j=i+i; j<1000005; j+=i) {
				sieve[j] += i;
			}
		} else order[i] = order[sieve[i]] + 1;
	}
	int ans = 0;
	for (i=0; i<1000005; i++) ans = max(ans, order[i]);
	memset(RSQ, 0, sizeof RSQ);
	for (i=2; i<1000005; i++)
		RSQ[order[i]][i] = 1;
	for (i=1; i<13; i++)
		for (j=1; j<1000005; j++)
			RSQ[i][j] += RSQ[i][j-1];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i, j;
	
	init();
	cin>>TC;
	while (TC--) {
		cin>>a>>b>>k;
		if (k > 12) cout<<"0\n";
		else cout<<RSQ[k][b]-RSQ[k][a-1]<<"\n";
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
