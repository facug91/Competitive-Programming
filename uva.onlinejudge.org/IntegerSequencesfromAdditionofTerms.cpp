/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=868
        Name: Integer Sequences from Addition of Terms
        Date: 07/03/2016
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
#define MOD 1000000007ll
#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

ll g, c[25], d, k, n, ans, b;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i;
	
	cin>>tc;
	while (tc--) {
		cin>>g;
		for (i=0; i<=g; i++) cin>>c[i];
		cin>>d>>k;
		n = 1ll;
		while (d * n < k) {
			k -= (d * n);
			n++;
		}
		ans = 0; b = 1;
		for (i=0; i<=g; i++, b*=n) ans += (c[i]*b);
		cout<<ans<<endl;
	}
	
	return 0;
}
