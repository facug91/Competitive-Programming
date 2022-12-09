/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=961
        Name: Minimal coverage
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

int m, l, r;
vii p, act;

struct cmp {
	bool operator() (const ii &a, const ii &b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first < b.first;
	}
};

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>m;
		p.clear();
		while (cin>>l>>r, l || r) p.push_back(ii(l, r));
		sort(p.begin(), p.end(), cmp());
		act.clear();
		act.push_back(p[0]); i = 1;
		while (i < p.size() && p[i].first <= 0) {
			if (act[0].second < p[i].second) act[0] = p[i];
			i++;
		}
		if (act[0].first <= 0 && act[0].second > 0) {
			bool ok = true;
			while (i<p.size() && ok && act.back().second < m) {
				if (p[i].first > act.back().second) ok = false;
				else if (p[i].second >= act.back().second) {
					if (act.size() > 1 && act[act.size()-2].second >= p[i].first) act.pop_back();
					act.push_back(p[i]);
				}
				i++;
			}
			if (ok && act.back().second >= m) {
				cout<<act.size()<<"\n";
				for (i=0; i<act.size(); i++) cout<<act[i].first<<" "<<act[i].second<<"\n";
			} else cout<<"0\n";
		} else cout<<"0\n";
		if (TC) cout<<"\n";
	}
	
	return 0;
}
