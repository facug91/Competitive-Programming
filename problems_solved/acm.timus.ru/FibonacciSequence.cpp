/*
	By: facug91
	From: http://acm.timus.ru/problem.aspx?space=1&num=1133
	Name: Fibonacci Sequence
	Date: 13/06/2016
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

ll i, fi, j, fj, k, fk, n;

bool check (ll fk) {
	ll a = fi, b = fk, c = a + b, s = i + 2;
	while (s < j) {
		a = b;
		b = c;
		c = a + b;
		s++;
		if (c > 1000000000000000ll) {
			c = LLONG_MAX;
			break;
		}
		if (c < -1000000000000000ll) {
			c = LLONG_MIN;
			break;
		}
	}
	return fj <= c;
}

ll binary_search () {
	ll lo = -2000000000ll, hi = 2000000000ll, mid;
	while (lo < hi - 1) {
		mid = (lo + hi) / 2ll;
		if (check(mid)) hi = mid;
		else lo = mid;
	}
	return hi;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(9); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	
	cin>>i>>fi>>j>>fj>>n;
	if (i > j) {
		swap(i, j);
		swap(fi, fj);
	}
	k = i + 1;
	if (i == j-1) {
		fk = fj;
		fj = fi + fk;
	} else {
		fk = binary_search();
		fj = fi + fk;
	}
	j = k + 1;
	if (n == i) cout<<fi<<endl;
	else if (n == k) cout<<fk<<endl;
	else if (n == j) cout<<fj<<endl;
	else if (n < i) {
		while (n < i) {
			fj = fk;
			fk = fi;
			fi = fj - fk;
			i--;
		}
		cout<<fi<<endl;
	} else /* if (n > j) */ {
		while (n > j) {
			fi = fk;
			fk = fj;
			fj = fi + fk;
			j++;
		}
		cout<<fj<<endl;
	}
	
	return 0;
}
