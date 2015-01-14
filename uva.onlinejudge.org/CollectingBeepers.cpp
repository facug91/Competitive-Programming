/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1437
        Name: Collecting Beepers
        Date: 07/01/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, w, h, x, y, DP[11][1<<11], limit, graph[11][11];
vector<ii> points;

int dp (int idx, int bitmask) {
	if (bitmask == limit) return graph[idx][0];
	if (DP[idx][bitmask] != -1) return DP[idx][bitmask];
	int ans = MAX_INT;
	for (int i=0; i<n; i++)
		if ((bitmask & (1<<i)) == 0)
			ans = min(ans, dp(i, bitmask|(1<<i))+graph[idx][i]);
	return DP[idx][bitmask] = ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j, k;
	
	cin>>TC;
	while (TC--) {
		cin>>w>>h;
		points.clear();
		cin>>x>>y;
		points.push_back(ii(x, y));
		cin>>n;
		for (i=0; i<n; i++) {
			cin>>x>>y;
			points.push_back(ii(x, y));
		}
		n++;
		for (i=0; i<n; i++) {
			for (j=i+1; j<n; j++) {
				graph[i][j] = graph[j][i] = abs(points[i].first-points[j].first)+abs(points[i].second-points[j].second);
			}
			graph[i][i] = 0;
		}
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++) {
				cerr<<graph[i][j]<<" ";
			}
			cerr<<endl;
		}
		limit = (1<<n)-1;
		memset(DP, -1, sizeof DP);
		cout<<"The shortest path has length "<<dp(0, 1)<<endl;
	}
	
	return 0;
}
