/*
	By: facug91
	From: http://lightoj.com/volume_showproblem.php?problem=1027
	Name: A Dangerous Maze
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

int n, a, sum, neg, num, den;

int gcd (int a, int b) {
	if (a == 0) return b;
	return gcd(b%a, a);
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
		neg = sum = 0;
		for (i=0; i<n; i++) {
			cin>>a;
			if (a < 0) neg++;
			sum += abs(a);
		}
		cout<<"Case "<<it<<": ";
		if (neg == n) cout<<"inf"<<endl;
		else {
			num = sum;
			den = n-neg;
			int aux = __gcd(num, den);
			cout<<num/aux<<"/"<<den/aux<<endl;
		}
	}
	
	return 0;
}
