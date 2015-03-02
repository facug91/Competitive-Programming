/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2767
        Name: Other Game
        Date: 02/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007ll
#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n;
ll DP[MAXN];

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j, l;
	
	DP[0] = 0ll;
	for (i=1; i<MAXN; i++) DP[i] = (DP[i-1] + ((ll)i*(ll)i)) % MOD;
	while (scanf("%d", &n) != EOF) printf("%lld\n", DP[n]);
	
	return 0;
}
