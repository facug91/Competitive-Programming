/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2668
        Name: Small Factors
        Date: 01/04/2015
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

ll m;
set<ll> DP;
set<ll>::iterator itr;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (ll a=1ll; a<=INT_MAX*6ll; a*=2ll) {
		DP.insert(a);
		for (ll b=1ll; a*b<=INT_MAX*6ll; b*=3) {
			DP.insert(a*b);
		}
	}
	while (cin>>m, m) {
		itr = DP.lower_bound(m);
		cout<<*itr<<"\n";
	}
	
	return 0;
}
