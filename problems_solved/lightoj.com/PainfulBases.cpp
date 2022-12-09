/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1021
	Name: Painful Bases
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

ll b, k, DP[20][1<<16], B_POW[21];
map<char, ll> to_int;
string num;

llu dp (int idx, int bm, int curr) {
	if (idx == num.length()) return (curr == 0);
	if (DP[curr][bm] != -1) return DP[curr][bm];
	DP[curr][bm] = 0;
	for (int i=0; i<num.length(); i++) if ((bm & (1<<i)) == 0) {
		DP[curr][bm] += dp(idx+1, bm|(1<<i), (curr + B_POW[idx] * to_int[num[i]]) % k);
	}
	return DP[curr][bm];
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
	
	to_int['0'] = 0;
	to_int['1'] = 1;
	to_int['2'] = 2;
	to_int['3'] = 3;
	to_int['4'] = 4;
	to_int['5'] = 5;
	to_int['6'] = 6;
	to_int['7'] = 7;
	to_int['8'] = 8;
	to_int['9'] = 9;
	to_int['A'] = 10;
	to_int['B'] = 11;
	to_int['C'] = 12;
	to_int['D'] = 13;
	to_int['E'] = 14;
	to_int['F'] = 15;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>b>>k>>num;
		memset(DP, -1, sizeof DP);
		B_POW[0] = 1;
		for (i=1; i<21; i++) B_POW[i] = (B_POW[i-1] * b) % k;
		cout<<"Case "<<it<<": "<<dp(0, 0, 0)<<endl;
	}
	
	return 0;
}
