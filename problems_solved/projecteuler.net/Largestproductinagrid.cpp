/*
	By: facug91
	From: https://projecteuler.net/problem=11
	Name: Largest product in a grid
	Date: 11/12/2016
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

int mat[20][20], ans;

int main () {
	//#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	//#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(9); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j, k, curr;
	
	ans = 0;
	for (i=0; i<20; i++) for (j=0; j<20; j++) cin>>mat[i][j];
	for (i=0; i<20; i++) for (j=0; j<20; j++) {
		k = 0; curr = 1;
		for (; k<4 && max(i, j)+k<20; k++) curr *= mat[i+k][j+k];
		if (k == 4) ans = max(ans, curr);
		
		k = 0; curr = 1;
		for (; k<4 && i+k<20; k++) curr *= mat[i+k][j];
		if (k == 4) ans = max(ans, curr);
		
		k = 0; curr = 1;
		for (; k<4 && j+k<20; k++) curr *= mat[i][j+k];
		if (k == 4) ans = max(ans, curr);
		
		k = 0; curr = 1;
		for (; k<4 && i+k<20 && j-k>=0; k++) curr *= mat[i+k][j-k];
		if (k == 4) ans = max(ans, curr);
	}
	cout << ans << endl	;
	
	return 0;
}
