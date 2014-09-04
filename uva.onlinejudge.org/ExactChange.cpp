/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2512
        Name: Exact Change
        Number: 11517
        Date: 27/08/2014
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

int price, n, bill[105];
ii DP[105][10020], ans;

ii dp (int idx, int act) {
	if (idx == n) return ii(INF, INF);
	if (DP[idx][act].first != -1) return DP[idx][act];
	ii aux0, aux1;
	if (act+bill[idx] >= price) {
		aux0 = ii(act+bill[idx], 1);
		aux1 = dp(idx+1, act);
		if (aux0.first == aux1.first) {
			if (aux0.second < aux1.second) return DP[idx][act] = aux0;
			else return DP[idx][act] = aux1;
		} else if (aux0.first < aux1.first) return DP[idx][act] = aux0;
		else return DP[idx][act] = aux1;
	} else {
		aux0 = dp(idx+1, act+bill[idx]);
		aux0.second++;
		aux1 = dp(idx+1, act);
		if (aux0.first == aux1.first) {
			if (aux0.second < aux1.second) return DP[idx][act] = aux0;
			else return DP[idx][act] = aux1;
		} else if (aux0.first < aux1.first) return DP[idx][act] = aux0;
		else return DP[idx][act] = aux1;
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>price;
		cin>>n;
		for (i=0; i<n; i++)
			cin>>bill[i];
		for (i=0; i<n; i++)
			for (j=0; j<10020; j++)
				DP[i][j].first = -1;
		ans = dp(0, 0);
		cout<<ans.first<<" "<<ans.second<<endl;
	}
	
	return 0;
}

