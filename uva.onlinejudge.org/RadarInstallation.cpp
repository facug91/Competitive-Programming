/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3634
        Name: Radar Installation
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

int n, ans;
double d, x, y, r;
vector<pair<double, double> > p;

struct cmp {
	bool operator() (const pair<double, double> &a, const pair<double, double> &b) {
		if (fabs(a.first - b.first) < EPS) return a.second > b.second;
		return a.first < b.first;
	}
};

double dist (const pair<double, double> &a, const pair<double, double> &b) {
	return hypot(a.first-b.first, a.second-b.second);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(10); cerr<<fixed<<setprecision(10);
	int tc = 1, i, j;
	
	while (cin>>n>>d, n || d) {
		p.clear();
		bool ok = true;
		for (i=0; i<n; i++) {
			cin>>x>>y;
			p.push_back(make_pair(x, y));
			if (y-d > EPS) ok = false;
		}
		if (!ok) cout<<"Case "<<tc++<<": -1\n";
		else {
			sort(p.begin(), p.end(), cmp());
			r = p[0].first + sqrt(d*d - p[0].second*p[0].second);
			ans = 1;
			for (i=1; i<n; i++) {
				if (p[i].first <= r) {
					r = min(r, p[i].first + sqrt(d*d - p[i].second*p[i].second));
				} else { //p[i].first > r
					if (dist(p[i], make_pair(r, 0.0))-d > EPS) {
						r = p[i].first + sqrt(d*d - p[i].second*p[i].second);
						ans++;
					}
				}
			}
			cout<<"Case "<<tc++<<": "<<ans<<"\n";
		}
	}
	
	return 0;
}
