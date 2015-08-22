/*
        By: facug91
        From: http://www.codechef.com/JULY15/problems/EGBOBRD/
        Name: Bread
        Date: 04/07/2015
*/
 
#include <bits/stdc++.h>
#define EPS 1e-9
#define MP make_pair
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10000100
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

ll n, k, a, ans, act;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n>>k;
		ans = act = 0ll;
		for (i=0; i<n; i++) {
			cin>>a;
			if (a >= k) {
				ans += (a / k);
				a -= ((a / k) * k);
			}
			if (act >= a) {
				act -= a;
			} else {
				a -= act;
				act = k;
				ans++;
				act -= a;
			}
			act = max(0ll, act-1ll);
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
