/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=36
        Name: The 3n + 1 problem
        Date: 19/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
#define MAXN 1000005
#define LOG 21

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int l, r, cycle[MAXN], DP[MAXN][LOG];

int calc (ll n) {
	if (n < (ll)MAXN) {
		if (cycle[(int)n] != -1) return cycle[(int)n];
		return cycle[(int)n] = calc((n%2ll==0ll)?n/2ll:n*3ll+1ll) + 1;
	}
	return calc((n%2ll==0ll)?n/2ll:n*3ll+1ll) + 1;
}
void init () {
	int i, j;
	memset(cycle, -1, sizeof cycle);
	cycle[0] = 0;
	cycle[1] = 1;
	for (i=2; i<MAXN; i++) {
		if (cycle[i] == -1) {
			cycle[i] = calc((ll)((i%2ll==0ll)?i/2ll:i*3ll+1ll)) + 1;
		}
	}
	for (i=0; i<MAXN; i++) {
		DP[i][0] = i;
	}
	for (j=1; (1<<j)<=MAXN; j++) {
		for (i=0; i+(1<<j)-1<MAXN; i++) {
			if (cycle[DP[i][j-1]] > cycle[DP[i+(1<<(j-1))][j-1]]) {
				DP[i][j] = DP[i][j-1];
			} else {
				DP[i][j] = DP[i+(1<<(j-1))][j-1];
			}
		}
	}
}
int rmq (int i, int j) {
	int k = (int)floor(log((double)j-i+1) / log(2.0));
	return max(cycle[DP[i][k]], cycle[DP[j-(1<<k)+1][k]]);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	init();
	while (cin>>l>>r) {
		cout<<l<<" "<<r<<" "<<rmq(min(l, r), max(l, r))<<endl;
	}
	
	return 0;
}
