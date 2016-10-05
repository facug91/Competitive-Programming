/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4142
        Name: Arranging Heaps
        Date: 21/09/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, k;
ll x[1005], w[1005], COST[1005][1005], DP[1005][1005];

void dp (int k, int l, int r, int opt_l, int opt_r) {
	if (l > r) return;
	int m = (l+r)/2, idx = -1;
	ll mn = LLONG_MAX;
	for (int i=opt_l; i<=opt_r && i<=m; i++) {
		if (mn > DP[k-1][i] + COST[i+1][m]) {
			mn = DP[k-1][i] + COST[i+1][m];
			idx = i;
		}
	}
	DP[k][m] = mn;
	dp(k, l, m-1, opt_l, idx);
	dp(k, m+1, r, idx, opt_r);
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	while (cin>>n>>k) {
		for (i=1; i<=n; i++) cin>>x[i]>>w[i];
		memset(COST, 0, sizeof COST);
		for (i=1; i<=n; i++) for (j=1; j<i; j++) COST[1][i] += (x[i] - x[j]) * w[j];
		for (i=3; i<=n; i++) for (j=2; j<i; j++) COST[j][i] = COST[j-1][i] - (x[i] - x[j-1]) * w[j-1];
		for (i=1; i<=n; i++) DP[1][i] = COST[1][i];
		for (i=2; i<=k; i++) dp(i, 1, n, 1, n);
		cout<<DP[k][n]<<endl;
	}
	
	return 0;
}
