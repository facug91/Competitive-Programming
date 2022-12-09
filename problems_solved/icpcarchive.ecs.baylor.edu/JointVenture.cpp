/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&Itemid=99999999&category=569&page=show_problem&problem=4286
        Name: Joint Venture
        Date: 23/07/2015
*/
 
#include <bits/stdc++.h>
#define y1 nd03dnqwuidg1odbnw9uddu0132d
#define EPS 1e-9
#define MP make_pair
#define DEB(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 4294967296ll
//#define MAXN 1001
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

ll x, n, a[1000005], l, r;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	while (cin>>x) {
		x *= 10000000ll;
		cin>>n;
		for (i=0; i<n; i++) cin>>a[i];
		bool first = true;
		sort(a, a+n);
		i = 0; j = n-1;
		while (i < j) {
			while (i < j && a[i]+a[j] > x) j--;
			if (i < j && a[i]+a[j] == x) {
				first = false;
				l = a[i];
				r = a[j];
				break;
			}
			i++;
		}
		if (first) cout<<"danger\n";
		else cout<<"yes "<<l<<" "<<r<<"\n";
	}
	
	return 0;
}
