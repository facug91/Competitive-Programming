/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1406
        Name: Homer Simpson
        Number: 10465
        Date: 09/09/2014
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
//#define MAXN 6005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int m, n, t;
ii ans, DP[10005];

ii dp (int time) {
	if (DP[time].first != -1) return DP[time];
	ii ans(0, time);
	if (time+m <= t) {
		ans = dp(time+m);
		ans.first++;
	}
	if (time+n <= t) {
		ii aux = dp(time+n);
		aux.first++;
		if (ans.second < aux.second) {
			ans = aux;
		} else if (ans.second == aux.second) {
			if (ans.first < aux.first)
				ans.first = aux.first;
		}
	}
	return DP[time] = ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>m>>n>>t) {
		for (i=0; i<=t; i++)
			DP[i].first = -1;
		ans = dp(0);
		cout<<ans.first;
		if (t-ans.second) cout<<" "<<t-ans.second;
		cout<<endl;
	}
	
	return 0;
}

