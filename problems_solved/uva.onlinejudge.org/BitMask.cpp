/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1659
        Name: Bit Mask
        Date: 07/04/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

ll n, l, u, m;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10);
	
	while (cin>>n>>l>>u) {
		m = 0ll;
		for (ll i=31; i>=0ll; i--) {
			if (((n & (1ll<<i)) == 0) && ((m|(1ll<<i)) >= l && (m|(1ll<<i)) <= u)) m |= (1ll<<i);
			if ((m|((1ll<<i)-1ll)) < l) m |= (1ll<<i);
		}
		cout<<m<<"\n";
	}
	
	return 0;
}
