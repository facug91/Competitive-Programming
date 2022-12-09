/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1007
        Name: Mathematically Hard
        Date: 12/05/2015
*/

#include <bits/stdc++.h>
#define left oiufg3782fdbeiwfdt2389dfa
#define right jsadh93dbh9d3hdgsakhdg973dh
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000003ll
#define MAXN 5000050

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;

unsigned long long DP[MAXN];
int a, b;
bool sieve[MAXN];

void dp () {
	unsigned long long i, j;
	for (i=0llu; i<MAXN; i++) DP[i] = i, sieve[i] = true;
	for (i=2llu; i<MAXN; i+=2llu) DP[i] /= 2llu;
	for (i=3llu; i<MAXN; i+=2llu) if (sieve[i]) {
		for (j=i; j<MAXN; j+=i) {
			DP[j] *= (i-1llu);
			DP[j] /= i;
			sieve[j] = false;
		}
	}
	for (i=1llu; i<MAXN; i++) DP[i] = DP[i]*DP[i] + DP[i-1];
}

int main () {
	int tc, i, j;
	
	dp();
	scanf("%d", &tc);
	for (int it=1; it<=tc; it++) {
		scanf("%d %d", &a, &b);
		printf("Case %d: %llu\n", it, DP[b]-DP[a-1]);
	}
	
	return 0;
}
