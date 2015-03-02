/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3115
        Name: Square Toys
        Date: 02/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, a, b, seq[1005], ans;

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j, l;
	
	cin>>TC;
	while (TC--) {
		m = 0; cin>>n;
		for (i=0; i<n; i++) cin>>a>>b, seq[i] = a+b, m = max(m, seq[i]);
		ans = 0;
		for (i=0; i<n; i++) ans += (m - seq[i]);
		cout<<ans<<endl;
	}
	
	return 0;
}
