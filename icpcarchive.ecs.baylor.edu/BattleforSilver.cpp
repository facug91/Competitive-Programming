/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=4634
        Name: Battle for Silver
        Date: 31/07/2015
*/
 
#include <bits/stdc++.h>
#define y1 nd03dnqwuidg1odbnw9uddu0132d
#define clock asoudh219udhjdgausdhs9udy
#define EPS 1e-9
#define MP make_pair
#define DEB(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 4294967296ll
#define MAXN 1001
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, m, s[455], u, v, ans;
bool adj[455][455];
ii edge[1000];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int i, j, k;
	
	while (cin>>n>>m) {
		for (i=0; i<n; i++) cin>>s[i];
		memset(adj, 0, sizeof adj);
		for (i=0; i<m; i++) {
			cin>>u>>v; u--; v--;
			adj[u][v] = adj[v][u] = true;
			edge[i].first = u;
			edge[i].second = v;
		}
		ans = -1;
		for (k=0; k<m; k++) {
			u = edge[k].first; v = edge[k].second;
			ans = max(ans, s[u] + s[v]);
			for (i=0; i<n; i++) if (i != u && i != v && adj[i][u] && adj[i][v]) {
				ans = max(ans, s[u] + s[v] + s[i]);
				for (j=i+1; j<n; j++) if (j != u && j != v && adj[j][u] && adj[j][v] && adj[j][i]) {
					ans = max(ans, s[u] + s[v] + s[i] + s[j]);
				}
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
