/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=1069
        Name: Soda Surpler
        Date: 13/05/2015
*/

#include <bits/stdc++.h>
#define left oiufg3782fdbeiwfdt2389dfa
#define right jsadh93dbh9d3hdgsakhdg973dh
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000003ll
//#define MAXN 5000050

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;

int e, f, c, ans;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>e>>f>>c;
		if (c == 1) cout<<"0\n";
		else {
			ans = 0;
			e += f;
			while (e >= c) {
				ans += (e/c);
				e = e/c + e%c;
			}
			cout<<ans<<"\n";
		}
	}
	
	return 0;
}
