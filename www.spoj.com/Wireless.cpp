/*
	By: facug91
	From: http://www.spoj.com/problems/WIRELESS/
	Name: Wireless
	Code: WIRELESS
	Date: 23/08/2014
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

int m, n, k, city[1005][30005], x, y, r, b, dis[1005], ans[1000005];

void update_ranges() {
	int i, j, r2 = r*r, lim;
	city[y][(x-r) >= 1 ? x-r : 1] += b;
	if (x+r+1 <= n) city[y][x+r+1] -= b;
	
	lim = min(r-1, max(y-1, m-y));
	for (i=1, j=0; i<=lim; i++, j++)
		dis[j] = (int) sqrt(r2-i*i);
	
	lim = min(m, y+r-1);
	for (i=y+1, j=0; i<=lim; i++, j++) {
		city[i][(x-dis[j]) >= 1 ? x-dis[j] : 1] += b;
		if (x+dis[j]+1 <= n) city[i][x+dis[j]+1] -= b;
	}
	if ((y+r) <= m) {
		city[y+r][x] += b;
		if (x < n) city[y+r][x+1] -= b;
	}
	lim = max(0, y-r+1);
	for (i=y-1, j=0; i>=lim; i--, j++) {
		city[i][(x-dis[j]) >= 1 ? x-dis[j] : 1] += b;
		if (x+dis[j]+1 <= n) city[i][x+dis[j]+1] -= b;
	}
	if ((y-r) >= 1) {
		city[y-r][x] += b;
		if (x < n) city[y-r][x+1] -= b;
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int i, j;
	
	scanf("%d", &m);
	scanf("%d", &n);
	scanf("%d", &k);
	
	swap(n, m);
	
	for (i=0; i<k; i++) {
		scanf("%d %d %d %d", &x, &y, &r, &b);
		swap(x, y);
		update_ranges();
	}
	
	for (i=1; i<=m; i++)
		for (j=1; j<=n; j++)
			ans[city[i][j] += city[i][j-1]]++;
	
	for (i=1000005; ans[i]==0; i--);
	
	printf("%d\n%d\n", i, ans[i]);
	
	return 0;
}

