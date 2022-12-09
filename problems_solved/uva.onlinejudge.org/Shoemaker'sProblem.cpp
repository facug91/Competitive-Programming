/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=967
        Name: Shoemaker's Problem
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

int n, t, s;
iii seq[1005];

struct cmp {
	bool operator() (const iii &a, const iii &b) {
		return a.second.second*b.second.first > b.second.second*a.second.first;
	}
};

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tc, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n;
		for (i=0; i<n; i++) cin>>seq[i].second.first>>seq[i].second.second, seq[i].first = i+1;
		stable_sort(seq, seq+n, cmp());
		cout<<seq[0].first;
		for (i=1; i<n; i++) cout<<" "<<seq[i].first;
		cout<<"\n";
		if (tc) cout<<"\n";
	}
	
	return 0;
}
