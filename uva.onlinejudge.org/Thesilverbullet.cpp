/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2168
        Name: The silver bullet
        Date: 16/02/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 10005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

struct cmp {
	bool operator() (const double& a, const double& b) const {
		if (fabs(a-b) < EPS) return false;
		return a < b;
	}
};

int n, ans;
double x, y;
vector<pair<double, double> > points;
map<double, int, cmp> counter;

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n;
		points.clear();
		for (i=0; i<n; i++) {
			cin>>x>>y;
			points.push_back(MP(x, y));
		}
		auto itr = unique(points.begin(), points.end());
		points.resize(distance(points.begin(), itr));
		if (points.size() == 1) cout<<"Data set #"<<it<<" contains a single gnu."<<endl;
		else {
			ans = 2;
			for (i=0; i<points.size(); i++) {
				counter.clear();
				for (j=i+1; j<points.size(); j++) {
					if (fabs(points[i].F-points[j].F) < EPS) counter[INF]++;
					else counter[(points[i].S-points[j].S)/(points[i].F-points[j].F)]++;
				}
				for (const auto& m : counter) ans = max(ans, m.S+1);
			}
			cout<<"Data set #"<<it<<" contains "<<points.size()<<" gnus, out of which a maximum of "<<ans<<" are aligned."<<endl;
		}
	}
	
	return 0;
}
