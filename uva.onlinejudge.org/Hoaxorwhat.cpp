/*
	By: facug91
	From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2077
	Name: Hoax or what
	Date: 29/04/2016
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
//#define MOD 1000000007ll
#define MAXN 100000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, k, a;
ll ans;
multiset<int> bill;
multiset<int>::iterator l, r;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	while (cin>>n, n) {
		ans = 0;
		bill.clear();
		for (i=0; i<n; i++) {
			cin>>k;
			for (j=0; j<k; j++) {
				cin>>a;
				bill.insert(a);
			}
			l = bill.begin();
			r = bill.end(); r--;
			ans += (ll)(*r - *l);
			bill.erase(l);
			bill.erase(r);
			cerr<<"bill size "<<bill.size()<<endl;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
