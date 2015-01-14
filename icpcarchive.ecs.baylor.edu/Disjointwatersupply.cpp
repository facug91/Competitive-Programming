/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4539
        Name: Disjoint water supply
        Date: 04/11/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int c, p, u, v, ans;
int DP[1005][1005];
vector<int> graph[1005];

int dp (int i, int j) {
	if (i == 1) return 1;
	if (i == j) return 0;
	if (DP[i][j] != -1) return DP[i][j];
	for (int k=0; k<(int)graph[j].size(); k++)
		if (dp(min(i, graph[j][k]), max(i, graph[j][k])))
			return DP[i][j] = 1;
	return DP[i][j] = 0;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>c>>p) {
		for (i=2; i<=c; i++)
			graph[i].clear();
		for (i=0; i<p; i++) {
			cin>>u>>v;
			graph[v].push_back(u);
		}
		memset(DP, -1, sizeof DP);
		ans = c-1;
		for (i=2; i<=c; i++)
			for (j=i+1; j<=c; j++)
				ans += dp(i, j);
		cout<<ans<<endl;
	}
	
	return 0;
}
