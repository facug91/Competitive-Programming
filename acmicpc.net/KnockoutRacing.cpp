/*
        By: facug91
        From: https://www.acmicpc.net/problem/10598
        Name: Knockout Racing
        Date: 27/05/2015
*/
 
#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10000100
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, m, a[1005], b[1005], d[1005], x, y, t, ans, act;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, j;
	
	cin>>n>>m;
	for (i=0; i<n; i++) {
		cin>>a[i]>>b[i];
		d[i] = abs(a[i]-b[i]);
	}
	while (m--) {
		ans = 0;
		cin>>x>>y>>t;
		for (i=0; i<n; i++) {
			if (t/d[i] % 2 == 0) {
				if (a[i] < b[i]) act = a[i]+t%d[i];
				else act = a[i]-t%d[i];
			} else {
				if (b[i] < a[i]) act = b[i]+t%d[i];
				else act = b[i]-t%d[i];
			}
			if (x <= act && act <= y) ans++;
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
