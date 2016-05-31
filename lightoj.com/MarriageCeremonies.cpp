/*
	By: facug91
	From: http://www.lightoj.com/volume_usersubmissions.php
	Name: Marriage Ceremonies
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

int n, mat[16][16], DP[16][1<<16];

int dp (int idx, int bm) {
	if (idx == n) return 0;
	if (DP[idx][bm] != -1) return DP[idx][bm];
	DP[idx][bm] = -1;
	for (int i=0; i<n; i++) if ((bm & (1<<i)) == 0) DP[idx][bm] = max(DP[idx][bm], dp(idx+1, bm|(1<<i)) + mat[idx][i]);
	return DP[idx][bm];
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
		for (i=0; i<n; i++) for (j=0; j<n; j++) cin>>mat[i][j];
		memset(DP, -1, sizeof DP);
		cout<<"Case "<<it<<": "<<dp(0, 0)<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
