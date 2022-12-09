/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3232
        Name: Penalty Calculation
        Date: 04/04/2015
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

int n, m, ans;
bool ac;
string v;
vector<pair<int, bool> > seq;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i;
	
	cin>>n;
	for (i=0; i<n; i++) {
		cin>>m>>v;
		if (v[0] == 'A') seq.push_back(make_pair(m, true));
		else seq.push_back(make_pair(m, false));
	}
	sort(seq.begin(), seq.end());
	ac = false; ans = 0;
	for (i=0; i<n && !ac; i++) {
		if (!seq[i].second) ans += 20;
		else {
			ans += seq[i].first;
			ac = true;
		}
	}
	if (ac) cout<<ans<<"\n";
	else cout<<"0\n";
	
	return 0;
}
