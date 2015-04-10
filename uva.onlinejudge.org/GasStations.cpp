/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3743
        Name: Gas Stations
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

int l, g, x, r;
vii seg, act;

struct cmp {
	bool operator() (const ii &a, const ii &b) {
		if (a.first == b.first) return a.second > b.second;
		return a.first < b.first;
	}
};

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10);
	int i, j;
	
	while (cin>>l>>g, l || g) {
		seg.clear();
		for (i=0; i<g; i++) {
			cin>>x>>r;
			seg.push_back(make_pair(x-r, x+r));
		}
		sort(seg.begin(), seg.end(), cmp());
		act.clear();
		act.push_back(seg[0]); i = 1;
		while (i < seg.size() && seg[i].first <= 0) {
			if (act[0].second < seg[i].second) act[0] = seg[i];
			i++;
		}
		if (act[0].first <= 0 && act[0].second > 0) {
			bool ok = true;
			while (i < seg.size() && ok && act.back().second < l) {
				if (act.back().second < seg[i].first) ok = false;
				else if (act.back().second < seg[i].second) {
					if (act.size() > 1 && act[act.size()-2].second >= seg[i].first) act.pop_back();
					act.push_back(seg[i]);
				}
				i++;
			}
			if (ok && act.back().second >= l) cout<<g - act.size()<<"\n";
			else cout<<"-1\n";
		} else cout<<"-1\n";
	}
	
	return 0;
}
