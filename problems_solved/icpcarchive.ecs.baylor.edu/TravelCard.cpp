/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4916
	Name: Travel Card
	Date: 28/04/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define next sbjkdfh329re9fdshfd98fyh
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 1000000007ll
#define MAXN 100000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, a[10005], b[10005], DP[10005][35][35];

int dp (int d, int la, int lb) {
	if (d == n) return 0;
	if (DP[d][la][lb] != -1) return DP[d][la][lb];
	int ans = a[d] * (la?0:1) + b[d] * (lb?0:2) + dp(d+1, max(la-1, 0), max(lb-1, 0));
	ans = min(ans, dp(d+1, max(la-1, 0), max(lb-1, 0)) + 3 + b[d] * (lb?0:2));
	ans = min(ans, dp(d+1, max(la-1, 0), max(lb-1, 0)) + 6);
	ans = min(ans, dp(d+1, max(la-1, 6), max(lb-1, 0)) + 18 + b[d] * (lb?0:2));
	ans = min(ans, dp(d+1, max(la-1, 6), max(lb-1, 0)) + 18 + 6);
	ans = min(ans, dp(d+1, max(la-1, 6), max(lb-1, 6)) + 36);
	ans = min(ans, dp(d+1, max(la-1, 29), max(lb-1, 0)) + 45 + b[d] * (lb?0:2));
	ans = min(ans, dp(d+1, max(la-1, 29), max(lb-1, 0)) + 45 + 6);
	ans = min(ans, dp(d+1, max(la-1, 29), max(lb-1, 6)) + 45 + 36);
	ans = min(ans, dp(d+1, max(la-1, 29), max(lb-1, 29)) + 90);
	//cerr<<"d "<<d<<" la "<<la<<" lb "<<lb<<" ans "<<ans<<endl;
	return DP[d][la][lb] = ans;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j, k;
	
	cin>>tc;
	while (tc--) {
		cin>>n;
		for (i=0; i<n; i++) cin>>a[i]>>b[i];
		memset(DP, -1, sizeof DP);
		cout<<dp(0, 0, 0)<<endl;
	}
	
	return 0;
}
