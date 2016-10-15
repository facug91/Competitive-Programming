/*
        By: facug91
        From: http://codeforces.com/gym/100818
        Name: Railway Tickets
        Date: 04/10/2016
*/

#include <bits/stdc++.h>

using namespace std;
#define F first
#define S second
#define INF 1000000000

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

int k, n, t, p, st, fn, RSQ[1005][10005];
bool in[1005][10005], ocup[1005][10005];
ll ans;

int main() {
	int i, j;
	
	scanf("%d %d %d", &k, &n, &t);
	for (i=0; i<t; i++) {
		scanf("%d %d %d", &p, &st, &fn);
		in[p][st] = true;
		for (j=st; j<=fn-1; j++) ocup[p][j] = true;
	}
	ans = 0;
	int from = 1, to = 1;
	for (i=1; i<=n; i++) {
		for (j=1; j<=k; j++) {
			if (!ocup[j][i] && !in[j][i]) {
				to = i+1;
				break;
			}
		}
		if (to < i+1) {
			ll len = to-from+1;
			ans += len*(len-1ll)/2ll;
			from = i + 1;
			to = i + 1;
		}
	}
	if (from < to) {
		ll len = n-from+1;
		ans += len*(len-1)/2;
	}
	
	
	for (i=1; i<=k; i++) {
		RSQ[i][n] = 0;
		for (j=n-1; j>=1; j--) {
			if (ocup[i][j] || in[i][j]) RSQ[i][j] = 0;
			else RSQ[i][j] = RSQ[i][j+1] + 1;
		}
	}
	
	for (i=1; i<=n; i++) {
		int mx = -1;
		for (j=1; j<=k; j++) mx = max(mx, RSQ[j][i]);
		ans -= mx;
	}
	
	printf("%lld\n", ans);
	
}
