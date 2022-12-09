/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1031
	Name: Easy Game
	Date: 06/07/2016
*/

#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define prev bjasdbi132ge79qwgdi
#define next usayhkdgisaydgiy212
#define move sdjifha978dyd9sag89
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 100000007
//#define MAXN 10000005

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, int> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; //insert, find_by_order, order_of_key, erase

int n, DP[105][105], a[105], RSQ[105];

int dp (int l, int r) {
	if (l > r) return 0;
	if (DP[l][r] != -INF) return DP[l][r];
	int sum = 0;
	for (int i=l; i<=r; i++) {
		sum += a[i];
		DP[l][r] = max(DP[l][r], (RSQ[r]-RSQ[i])-dp(i+1, r) + sum);
		//cerr<<"l "<<l<<" r "<<r<<" i "<<i<<" RSQ "<<RSQ[r]<<" - "<<RSQ[i]<<" dp i+1 r "<<dp(i+1, r)<<" sum "<<sum<<endl;
	}
	sum = 0;
	for (int i=r; i>=l; i--) {
		sum += a[i];
		DP[l][r] = max(DP[l][r], (RSQ[i-1]-RSQ[l-1])-dp(l, i-1) + sum);
		//cerr<<"l "<<l<<" r "<<r<<" i "<<i<<" RSQ "<<RSQ[r]<<" - "<<RSQ[i]<<" dp i+1 r "<<dp(i+1, r)<<" sum "<<sum<<endl;
	}
	return DP[l][r];
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n;
		for (i=1; i<=n; i++) cin>>a[i];
		for (i=0; i<=n; i++) for (j=0; j<=n; j++) DP[i][j] = -INF;
		RSQ[0] = 0;
		for (i=1; i<=n; i++) RSQ[i] = RSQ[i-1] + a[i];
		int a = dp(1, n);
		int b = RSQ[n] - a;
		cout<<"Case "<<it<<": "<<a-b<<endl;
	}
	
	return 0;
}
