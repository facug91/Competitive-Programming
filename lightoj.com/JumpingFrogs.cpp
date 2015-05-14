/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1156
        Name: Jumping Frogs
        Date: 04/05/2015
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
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, d, m, ans;
char s;
vector<pair<int, bool> > stones;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n>>d;
		stones.clear();
		stones.push_back(make_pair(0, true));
		for (i=0; i<n; i++) {
			cin>>s;
			cin.ignore(INT_MAX, '-');
			cin>>m;
			stones.push_back(make_pair(m, s=='B'));
		}
		stones.push_back(make_pair(d, true));
		ans = -1;
		for (i=1; i<stones.size(); i++) {
			if (!stones[i-1].second) ans = max(ans, stones[i].first-stones[i-2].first);
			else ans = max(ans, stones[i].first-stones[i-1].first);
		}
		cout<<"Case "<<it<<": "<<ans<<"\n";
	}
	
	return 0;
}
