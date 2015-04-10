/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2231
        Name: Coin Collector
        Date: 06/04/2015
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

ll n, c[1005], sum, ans;
stack<int> stk;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tc, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n;
		for (i=0; i<n; i++) cin>>c[i];
		ans = sum = 0;
		sort(c, c+n);
		while (stk.size()) stk.pop();
		for (i=0; i<n; i++) {
			while (sum >= c[i]) {
				sum -= stk.top();
				stk.pop();
			}
			stk.push(c[i]);
			sum += c[i];
			ans = max(ans, (ll)stk.size());
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
