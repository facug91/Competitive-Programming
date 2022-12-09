/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4799
        Name: Going Postal
        Date: 15/01/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
typedef vector<int> vi;
typedef vector<ii> vii;

int p, w, h, x, y, limit;
double s, d, adj[25][25], DP[20][1<<20];
ii post[25];

double dp (int idx, int bitmask) {
	if (DP[idx][bitmask] != -0.5) return DP[idx][bitmask];
	if (bitmask == limit) return DP[idx][bitmask] = d + adj[idx][0];
	double ans = MAX_DBL;
	for (int i=0; i<p; i++)
		if ((bitmask & (1<<i)) == 0)
			ans = min(ans, dp(i, bitmask | (1<<i)) + adj[idx][i]);
	return DP[idx][bitmask] = ans + d;
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>p>>w>>h>>s>>d;
		for (i=0; i<p; i++) for (j=0; j<(1<<p); j++) DP[i][j] = -0.5;
		for (i=0; i<p; i++)	cin>>post[i].first>>post[i].second;
		for (i=0; i<p; i++) {
			for (j=0; j<p; j++)	adj[i][j] = adj[j][i] = (double)(abs(post[i].first-post[j].first) * w + abs(post[i].second-post[j].second) * h) / s;
			adj[i][i] = 0.0;
		}
		limit = (1<<p)-1;
		int ans = (int)dp(0, 1);
		printf("%02d:%02d\n", (18+ans/60)%24, ans%60);
	}
	
	return 0;
}
