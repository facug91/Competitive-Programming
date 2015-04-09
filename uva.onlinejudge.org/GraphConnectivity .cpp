/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=400
        Name: Graph Connectivity
        Date: 09/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n;
string s;
bool adj[30][30], vis[30];

int dfs (int u) {
	vis[u] = true;
	int ans = 1;
	for (int v=0; v<n; v++) if (adj[u][v] && !vis[v]) ans += dfs(v);
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i, j;
	
	cin>>TC;
	getline(cin, s);
	getline(cin, s);
	while (TC--) {
		getline(cin, s);
		n = s[0] - 'A' + 1;
		memset(adj, 0, sizeof adj);
		while (getline(cin, s), s.length()) adj[s[0]-'A'][s[1]-'A'] = adj[s[1]-'A'][s[0]-'A'] = true;
		int ans = 0;
		memset(vis, 0, sizeof vis);
		for (i=0; i<n; i++) if (!vis[i]) {
			dfs(i);
			ans++;
		}
		cout<<ans<<"\n";
		if (TC) cout<<"\n";
	}
	
	return 0;
}
