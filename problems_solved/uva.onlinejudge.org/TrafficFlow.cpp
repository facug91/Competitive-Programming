/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1783
        Name: Traffic Flow
        Date: 13/05/2015
*/

#include <bits/stdc++.h>
#define left oiufg3782fdbeiwfdt2389dfa
#define right jsadh93dbh9d3hdgsakhdg973dh
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000003ll
#define MAXN 5000050

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, u, v, w, adj[105][105], ans;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j, k;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		for (i=0; i<n; i++) for (j=0; j<n; j++) adj[i][j] = -INF;
		cin>>n>>m;
		for (i=0; i<m; i++) {
			cin>>u>>v>>w;
			if (w > adj[u][v]) adj[u][v] = adj[v][u] = w;
		}
		for (k=0; k<n; k++)
			for (i=0; i<n; i++)
				for (j=0; j<n; j++)
						adj[i][j] = max(adj[i][j], min(adj[i][k], adj[k][j]));
		ans = INT_MAX;
		for (i=0; i<n; i++)
			for (j=0; j<n; j++)
					ans = min(ans, adj[i][j]);
		cout<<"Case #"<<it<<": "<<ans<<"\n";
	}
	
	return 0;
}
