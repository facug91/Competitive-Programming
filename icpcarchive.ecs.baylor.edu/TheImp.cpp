/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4949
        Name: The Imp
        Date: 08/10/2016
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
ll DP[150005][10];
pair<ll, ll> item[150005];

ll dp (int idx, int k) {
	if (idx == n) return 0;
	if (DP[idx][k] != LLONG_MIN) return DP[idx][k];
	if (k == 0) return DP[idx][k] = max(item[idx].F - item[idx].S, dp(idx+1, k));
	return DP[idx][k] = max(dp(idx+1, k), min(dp(idx+1, k-1) - item[idx].S, item[idx].F - item[idx].S));
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(6); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	
	cin>>tc;
	while (tc--) {
		cin>>n>>k;
		for (i=0; i<n; i++) cin>>item[i].F>>item[i].S;
		sort(item, item+n, [](const pair<ll, ll>& a, const pair<ll, ll>&b) {return a.F<b.F;});
		for (i=0; i<=n; i++) for (j=0; j<=k; j++) DP[i][j] = LLONG_MIN;
		cout<<dp(0, k)<<endl;
	}
	
	return 0;
}
