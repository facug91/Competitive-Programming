/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2384
        Name: The Bus Driver Problem
        Date: 05/04/2015
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

int n, d, r, route[2][105], ans;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, j;
	
	while (cin>>n>>d>>r, n || d || r) {
		for (i=0; i<n; i++) cin>>route[0][i];
		for (i=0; i<n; i++) cin>>route[1][i];
		sort(route[0], route[0]+n, less<int>());
		sort(route[1], route[1]+n, greater<int>());
		ans = 0;
		for (i=0; i<n; i++) ans += (max(route[0][i] + route[1][i] - d, 0) * r);
		cout<<ans<<"\n";
	}
	
	return 0;
}
