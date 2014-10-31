/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1867
        Name: How Many Dependencies?
        Date: 28/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, t, u, ans, mx, aux;
vector<int> graph[105];
bool vis[105];

int dfs (int idx) {
	vis[idx] = true;
	int ans = 1;
	for (int i=0; i<(int)graph[idx].size(); i++)
		if (!vis[graph[idx][i]]) 
			ans += dfs(graph[idx][i]);
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>n, n) {
		for (i=1; i<=n; i++)
			graph[i].clear();
		for (i=1; i<=n; i++) {
			cin>>t;
			for (j=0; j<t; j++) {
				cin>>u;
				graph[i].push_back(u);
			}
		}
		mx = -1;
		for (i=1; i<=n; i++) {
			for (j=1; j<=n; j++)
				vis[j] = false;
			aux = dfs(i);
			if (mx < aux) {
				mx = aux;
				ans = i;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
