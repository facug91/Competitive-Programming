/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&Itemid=99999999&category=706&page=show_problem&problem=5380
	Name: Word Clouds Revisited
	Date: 10/05/2016
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

int n, c, DP[5005], s[5005][2];

int dp (int idx) {
	if (idx == n) return 0;
	if (DP[idx] != -1) return DP[idx];
	int w = s[idx][0], h = s[idx][1];
	int ans = dp(idx+1) + h;
	for (int i=idx+1; i<n; i++) {
		w += s[i][0];
		h = max(h, s[i][1]);
		if (w > c) break;
		ans = min(ans, dp(i+1) + h);
	}
	return DP[idx] = ans;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1;
	
	while (cin>>n>>c) {
		for (int i=0; i<n; i++) cin>>s[i][0]>>s[i][1];
		memset(DP, -1, sizeof DP);
		cout<<dp(0)<<endl;
	}
	
	return 0;
}
