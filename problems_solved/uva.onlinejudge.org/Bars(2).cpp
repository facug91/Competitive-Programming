/*
	By: facug91
	From: Bars
	Name: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3886
	Date: 21/04/2017
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
#define MAXN 1000

using namespace std;
//using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<ll, ll> ii; typedef pair<ii, int> iii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; //insert, find_by_order, order_of_key, erase

int tc, n, p, a[25];

bool search (int curr, int sum) {
	if (curr == p || sum > n) return false;
	if (sum + a[curr] == n) return true;
	return search(curr + 1, sum + a[curr]) || search(curr + 1, sum);
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(9); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	
	cin >> tc;
	for (int it = 1; it <= tc; it++) {
		cin >> n >> p;
		for (int i = 0; i < p; i++) cin >> a[i];
		if (n == 0 || search(0, 0)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
