/*
	By: facug91
	From: http://www.spoj.com/problems/TAP2013J/
	Name: Game of stones
	Date: 26/05/2016
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
#define MOD 1000000007
//#define MAXN 10000005

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, int> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int n, DP[1005][1005];

int dp (int k, int n) {
	if (n == 0 && k == 0) return 1;
	if (n <= 0 || k <= 0) return 0;
	if (DP[k][n] != -1) return DP[k][n];
	return DP[k][n] = (dp(k, n-k) + dp(k-1, n-1)) % MOD;
}

int main () {
	//#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	//#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n;
		memset(DP, -1, sizeof DP);
		int ans = 0;
		for (i=1; i<=n; i++) if ((n-i) % 2 == 1) ans = (ans + dp(i, n)) % MOD;
		cout<<ans<<endl;
	}
	
	return 0;
}
