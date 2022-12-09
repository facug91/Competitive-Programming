/*
	By: facug91
	From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2225
	Name: String Partition
	Date: 04/07/2016
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, int> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; //insert, find_by_order, order_of_key, erase

ll DP[205][15], n, a[205];
string s;

ll dp (int idx, int len, ll sum) {
	if (idx == n-1) return sum;
	if (DP[idx][len] != -1) return DP[idx][len];
	if (sum*10 + a[idx+1] > INT_MAX) return DP[idx][len] = dp(idx+1, 1, a[idx+1]) + sum;
	return DP[idx][len] = max(dp(idx+1, 1, a[idx+1]) + sum, dp(idx+1, len+1, sum*10+a[idx+1]));
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j, k;
	
	cin>>tc;
	while (tc--) {
		cin>>s;
		n = s.length();
		for (i=0; i<n; i++) a[i] = s[i]-'0';
		memset(DP, -1, sizeof DP);
		cout<<dp(0, 1, a[0])<<endl;
	}
	
	return 0;
}
