/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=989
        Name: Audiophobia
        Date: 10/03/2015
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

int c, s, q, adj[105][105], a, b, d;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC = 1, i, j, k;
	
	while (cin>>c>>s>>q, c || s || q) {
		if (TC != 1) cout<<"\n";
		for (i=0; i<c; i++) for (j=0; j<c; j++) adj[i][j] = INF;
		for (i=0; i<s; i++) {
			cin>>a>>b>>d; a--; b--;
			adj[a][b] = adj[b][a] = d;
		}
		for (k=0; k<c; k++)
			for (i=0; i<c; i++)
				for (j=0; j<c; j++)
					adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]));
		cout<<"Case #"<<TC++<<"\n";
		for (i=0; i<q; i++) {
			cin>>a>>b; a--; b--;
			if (adj[a][b] == INF) cout<<"no path\n";
			else cout<<adj[a][b]<<"\n";
		}
	}
	
	return 0;
}
