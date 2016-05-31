/*
	By: facug91
	From: http://www.lightoj.com/volume_showproblem.php?problem=1231
	Name: Coin Change (I)
	Date: 20/05/2016
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
#define MOD 100000007
//#define MAXN 30015

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, k, a[50], c[50], DP[51][1001];

int dp (int idx, int sum) {
	if (sum == k) return 1;
	if (sum > k || idx == n) return 0;
	if (DP[idx][sum] != -1) return DP[idx][sum];
	DP[idx][sum] = dp(idx+1, sum);
	for (int i=0; i<c[idx]; i++) DP[idx][sum] = (DP[idx][sum] + dp(idx+1, sum+a[idx]*(i+1))) % MOD;
	return DP[idx][sum];
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n>>k;
		for (i=0; i<n; i++) cin>>a[i];
		for (i=0; i<n; i++) cin>>c[i];
		memset(DP, -1, sizeof DP);
		cout<<"Case "<<it<<": "<<dp(0, 0)<<endl;
	}
	
	return 0;
}
