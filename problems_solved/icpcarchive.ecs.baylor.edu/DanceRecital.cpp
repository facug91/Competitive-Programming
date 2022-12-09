/*
	By: facug91
	From: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=706&problem=5374&mosmsg=Submission+received+with+ID+1954565
	Name: Dance Recital
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


int n, DP[11][1<<11], dis[11][11];
string s[11];

int dist (int u, int v) {
	int ans = 0;
	for (int i=0; i<s[u].length(); i++) 
		for (int j=0; j<s[v].length(); j++)
			if (s[u][i] == s[v][j]) ans++;
	return ans;
}

int dp (int prev, int bm) {
	if (bm == ((1<<n)-1)) return 0;
	if (DP[prev][bm] != -1) return DP[prev][bm];
	int ans = INT_MAX;
	for (int i=0; i<n; i++) if ((bm & (1<<i)) == 0) {
		ans = min(ans, dp(i, bm|(1<<i)) + dist(prev, i));
	}
	return DP[prev][bm] = ans;
}


int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1;
	
	while (cin>>n) {
		for (int i=0; i<n; i++) cin>>s[i];
		int ans = INT_MAX;
		memset(DP, -1, sizeof DP);
		for (int i=0; i<n; i++) ans = min(dp(i, (1<<i)), ans);
		cout<<ans<<endl;
	}
	
	return 0;
}
