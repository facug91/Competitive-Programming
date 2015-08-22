/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1221
        Name: Travel Company
        Date: 22/05/2015
*/
 
#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 10000100
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, m, p, adj[105][105], u, v, I, E;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j, k;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n>>m>>p;
		for (i=0; i<n; i++) for (j=0; j<n; j++) adj[i][j] = INF;
		for (i=0; i<m; i++) {
			cin>>u>>v>>I>>E;
			adj[u][v] = E*p-I;
		}
		for (k=0; k<n; k++)
			for (i=0; i<n; i++)
				for (j=0; j<n; j++)
					adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
		bool ans = false;
		for (i=0; i<n; i++) if (adj[i][i] < 0) ans = true;
		if (ans) cout<<"Case "<<it<<": YES\n";
		else cout<<"Case "<<it<<": NO\n";
	}
	
	return 0;
}
