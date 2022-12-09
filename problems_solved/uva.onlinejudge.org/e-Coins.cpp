/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1247
        Name: e-Coins
        Number: 10306
        Date: 26/08/2014
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
//#define MAXN N

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, s, DP[305][305], ans;
ii coin[50];

int dp (int x, int y) {
	if (x > 300 || y > 300) return MAX_INT;
	if (DP[x][y] != -1) return DP[x][y];
	if (x*x+y*y == s) return DP[x][y] = 0;
	int ans = MAX_INT, aux;
	for (int i=0; i<n; i++) {
		aux = dp(x+coin[i].first, y+coin[i].second);
		if (aux != MAX_INT) ans = min(ans, aux);
	}
	if (ans != MAX_INT) ans++;
	return DP[x][y] = ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n>>s;
		for (i=0; i<n; i++)
			cin>>coin[i].first>>coin[i].second;
		memset(DP, -1, sizeof DP);
		s *= s;
		ans = dp(0, 0);
		if (ans == MAX_INT) cout<<"not possible\n";
		else cout<<ans<<endl;
	}
	
	return 0;
}

