/*
	By: facug91
	From: http://acm.timus.ru/problem.aspx?space=1&num=1260
	Name: Nudnik Photographer
	Date: 25/06/2016
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

int n, DP[60][1<<5];

int dp (int idx, int bm) {
	//cerr<<"idx "<<idx<<" bm "<<bm<<endl;
	if (DP[idx][bm] != -1) return DP[idx][bm];
	if (idx >= n) return 0;
	if (idx == n-1 && bm == 7) return 1;
	if (idx == n-2 && bm == 15) return 1;
	if ((bm & 1) == 0) {
		if (idx == n-1) return 1;
		return 0ll;
	}
	if ((bm & 2) == 0) {
		return DP[idx][bm] = dp(idx+1, 6) + dp(idx-1, 15) + (idx+2 < n);
	}
	if ((bm & 8) != 0) {
		return DP[idx][bm] = dp(idx+2, 7);
	}
	return DP[idx][bm] = dp(idx+1, 7) + dp(idx+2, 5);
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
	
	cin>>n; n += 2;
	memset(DP, -1, sizeof DP);
	cout<<dp(2, 7)<<endl;
	
	return 0;
}
