/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1014
        Name: Ifter Party
        Date: 12/05/2015
*/

#include <bits/stdc++.h>
#define left oiufg3782fdbeiwfdt2389dfa
#define right jsadh93dbh9d3hdgsakhdg973dh
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000003ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;

ll p, l;
vi divs, left, right;

void solve (ll n) {
	ll i, j;
	divs.clear(); left.clear(); right.clear();
	if (n == 1ll) {
		divs.push_back(1ll);
		return;
	}
	left.push_back(1ll);
	right.push_back(n);
	i = 2ll;
	while (i*i <= n) {
		if (n % i == 0ll) {
			left.push_back(i);
			right.push_back(n/i);
		}
		i++;
	}
	if (left.back() == right.back()) right.pop_back();
	for (i=0; i<left.size(); i++) divs.push_back(left[i]);
	for (i=(int)right.size()-1; i>=0; i--) divs.push_back(right[i]);
}

int main () {
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>p>>l;
		solve(p-l);
		if (divs.back() <= l) cout<<"Case "<<it<<": impossible\n";
		else {
			cout<<"Case "<<it<<":";
			for (i=0; i<divs.size(); i++) if (divs[i] > l) cout<<" "<<divs[i];
			cout<<"\n";
		}
	}
	
	return 0;
}
