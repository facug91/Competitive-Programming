/*
	By: facug91
	From: http://www.lightoj.com/volume_showproblem.php?problem=1005
	Name: Rooks
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
//#define MOD 1000000000ll
//#define MAXN 30015

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

ll n, k, DP[30][30];

ll dp (ll idx, ll used) {
	if (used == k) return 1;
	if (idx == n) return 0;
	if (DP[idx][used] != -1) return DP[idx][used];
	return DP[idx][used] = dp(idx+1, used+1) * (n-used) + dp(idx+1, used);
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
		cout<<"Case "<<it<<": ";
		if (k > n) cout<<0<<endl;
		else {
			memset(DP, -1, sizeof DP);
			cout<<dp(0, 0)<<endl;
		}
	}
	
	return 0;
}
