/*
        By: facug91
        From: http://www.codechef.com/JULY15/problems/MCHEF
        Name: MasterChef
        Date: 07/07/2015
*/
 
#include <bits/stdc++.h>
#define EPS 1e-9
#define DEB(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10000100
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

ll n, k, m, a[100005], cost[100005], DP[100005][505], l, r, c;
vector<pair<ii, int> > intervals;
priority_queue<pair<int, ii>, vector<pair<int, ii> >, greater<pair<int, ii> > > pq;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int tc, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n>>k>>m;
		for (i=1; i<=n; i++) cin>>a[i];
		intervals.clear();
		for (i=0; i<m; i++) {
			cin>>l>>r>>c;
			intervals.push_back(make_pair(ii(l, r), c));
		}
		sort(intervals.begin(), intervals.end());
		while (pq.size()) pq.pop();
		i = 1; j = 0;
		while (i <= n) {
			while (j < intervals.size() && intervals[j].first.first <= i) {
				pq.push(make_pair(intervals[j].second, intervals[j].first));
				j++;
			}
			while (pq.size() && pq.top().second.second < i) pq.pop();
			if (pq.size() && a[i] < 0) {
				cost[i] = pq.top().first;
			} else cost[i] = INF;
			i++;
		}
		for (i=0; i<=n; i++) for (j=0; j<=k; j++) DP[i][j] = 0;
		for (i=1; i<=n; i++) for (j=0; j<=k; j++) {
			if (a[i] < 0 && cost[i] <= j) DP[i][j] = max(DP[i-1][j], DP[i-1][j-cost[i]]-a[i]);
			else DP[i][j] = DP[i-1][j];
		}
		ll ans = 0ll, desc = 0ll;
		for (j=0; j<=k; j++) desc = max(desc, DP[n][j]);
		for (i=1; i<=n; i++) ans += a[i];
		ans += desc;
		cout<<ans<<"\n";
	}
	
	return 0;
}
