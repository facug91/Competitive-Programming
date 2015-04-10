/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1323
        Name: Watering Grass
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

int n;
double l, w, p, r, aux;
vector<pair<double, double> > seq, act;

struct cmp {
	bool operator() (const pair<double, double> &a, const pair<double, double> &b) {
		if (fabs(a.first - b.first) < EPS) return a.second > b.second;
		return a.first < b.first;
	}
};

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, j;
	
	while (cin>>n>>l>>w) {
		seq.clear();
		for (i=0; i<n; i++) {
			cin>>p>>r;
			aux = sqrt(r*r - w*w/4.0);
			seq.push_back(make_pair(p-aux, p+aux));
		}
		sort(seq.begin(), seq.end(), cmp());
		act.clear();
		if (seq[0].first <= EPS) {
			bool ok = true;
			act.push_back(seq[0]); i = 1;
			while (i < seq.size() && ok && act.back().second <= l) {
				if (seq[i].first > act.back().second) ok = false;
				else if (seq[i].second > act.back().second) {
					if (act.size() > 1 && act[act.size()-2].second >= seq[i].first) act.pop_back();
					act.push_back(seq[i]);
				}
				i++;
			}
			if (ok && act.back().second >= l) {
				cout<<act.size()<<"\n";
			} else cout<<"-1\n";
		} else cout<<"-1\n";
	}
	
	return 0;
}
