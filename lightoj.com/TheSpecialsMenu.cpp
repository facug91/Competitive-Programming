/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1025
	Name: The Specials Menu
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

ll DP[65][65];
string s;

ll dp (int l, int r) {
	if (l > r) return 0;
	if (l == r) return 1;
	if (DP[l][r] != -1) return DP[l][r];
	DP[l][r] = 0;
	if (s[l] == s[r]) DP[l][r] += dp(l+1, r-1) + 1;
	DP[l][r] += dp(l+1, r) + dp(l, r-1) - dp(l+1, r-1);
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
		cin>>s;
		memset(DP, -1, sizeof DP);
		cout<<"Case "<<it<<": "<<dp(0, s.length())-1<<endl;
	}
	
	return 0;
}
