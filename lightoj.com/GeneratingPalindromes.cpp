/*
	By: facug91
	From: http://www.lightoj.com/volume_showproblem.php?problem=1033
	Name: Generating Palindromes
	Date: 23/05/2016
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

int DP[105][105];
string s;

int dp (int l, int r) {
	if (l >= r) return 0;
	if (DP[l][r] != -1) return DP[l][r];
	DP[l][r] = min(dp(l+1, r-1) + (s[l] != s[r]) * 2,
				   min(dp(l+1, r) + 1, dp(l, r-1) + 1));
	return DP[l][r];
}

int main () {
	//#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	//#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>s;
		memset(DP, -1, sizeof DP);
		cout<<"Case "<<it<<": "<<dp(0, s.length()-1)<<endl;
	}
	
	return 0;
}
