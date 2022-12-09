/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2714
        Name: Food and Medicine
        Date: 11/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, m, a, b, c, adj[105][105], q;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i, j, k;
	
	cin>>TC;
	while (TC--) {
		cin>>n>>m;
		for (i=0; i<n; i++) for (j=0; j<n; j++) adj[i][j] = INF;
		for (i=0; i<n; i++) adj[i][i] = 0;
		for (i=0; i<m; i++) {
			cin>>a>>b>>c; a--; b--;
			if (adj[a][b] > c) adj[a][b] = adj[b][a] = c;
		}
		for (k=0; k<n; k++)
			for (i=0; i<n; i++)
				for (j=0; j<n; j++)
					adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
		cin>>q;
		for (i=0; i<q; i++) {
			cin>>a>>b; a--; b--;
			if (adj[a][b] == INF) cout<<"-1\n";
			else cout<<adj[a][b]<<"\n";
		}
		if (TC) cout<<"\n";
	}
	
	return 0;
}
