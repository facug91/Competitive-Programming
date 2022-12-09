/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2098
        Name: Dynamic Frog
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

int n, d, rp[105], ans;
char rt[105];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10);
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n>>d;
		rt[0] = 'B'; rp[0] = 0;
		for (i=1; i<=n; i++) {
			cin>>rt[i];
			cin.ignore(INT_MAX, '-');
			cin>>rp[i];
		}
		rt[n+1] = 'B'; rp[n+1] = d;
		ans = -1;
		for (i=0; i<=n; i++) {
			if (rt[i+1] == 'S') ans = max(ans, max(rp[i+1]-rp[i], rp[i+2]-rp[i]));
			else ans = max(ans, rp[i+1]-rp[i]);
		}
		cout<<"Case "<<it<<": "<<ans<<"\n";
	}
	
}
