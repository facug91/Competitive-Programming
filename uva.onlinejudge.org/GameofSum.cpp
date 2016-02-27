/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1832
        Name: Game of Sum
        Date: 26/02/2016
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
#define MOD 1000000007ll
//#define MAXN 10005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n;
ll a[105], RSQ[105], DP[105][105];

ll rsq (int l, int r) {
	return RSQ[r] - RSQ[l-1];
}

ll dp (int l, int r) {
	if (DP[l][r] != -1ll) return DP[l][r];
	if (l == r) return DP[l][r] = a[l];
	ll ans = rsq(l, r);
	for (int i=l; i<r; i++) ans = max(ans, rsq(l, i) + rsq(i+1, r) - dp(i+1, r));
	for (int i=r; i>l; i--) ans = max(ans, rsq(i, r) + rsq(l, i-1) - dp(l, i-1));
	return DP[l][r] = ans;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	while (cin>>n, n) {
		RSQ[0] = 0ll;
		for (i=1; i<=n; i++) {
			cin>>a[i];
			RSQ[i] = RSQ[i-1] + a[i];
		}
		memset(DP, -1, sizeof DP);
		cout<<dp(1, n) - rsq(1, n) + dp(1, n)<<endl;
	}
	
	return 0;
}
