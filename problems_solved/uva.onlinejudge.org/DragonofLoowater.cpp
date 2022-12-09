/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2267
        Name: Dragon of Loowater
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

int n, m, h[20005], w[20005], ans;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10);
	int i, j;
	
	while (cin>>n>>m, n || m) {
		for (i=0; i<n; i++) cin>>h[i];
		for (i=0; i<m; i++) cin>>w[i];
		sort(h, h+n);
		sort(w, w+m);
		i = j = ans = 0;
		while (i < n && j < m) {
			while (j < m && h[i] > w[j]) j++;
			if (j < m && h[i] <= w[j]) {
				i++;
				ans += w[j];
			}
			j++;
		}
		if (i == n) cout<<ans<<"\n";
		else cout<<"Loowater is doomed!\n";
	}
	
	return 0;
}
