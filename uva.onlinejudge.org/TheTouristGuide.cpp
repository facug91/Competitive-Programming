/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1040
        Name: The Tourist Guide
        Date: 24/04/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, r, c0, c1, p, adj[105][105], s, d, t;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc = 1, i, j, k;
	
	while (cin>>n>>r, n || r) {
		for (i=0; i<n; i++) {
			for (j=0; j<n; j++) adj[i][j] = -INF;
			adj[i][i] = 0;
		}
		for (i=0; i<r; i++) {
			cin>>c0>>c1>>p; c0--; c1--;
			if (adj[c0][c1] < p) adj[c0][c1] = adj[c1][c0] = p;
		}
		for (k=0; k<n; k++)
			for (i=0; i<n; i++)
				for (j=0; j<n; j++)
					adj[i][j] = max(adj[i][j], min(adj[i][k], adj[k][j]));
		cin>>s>>d>>t; s--; d--; adj[s][d]--;
		cout<<"Scenario #"<<tc++<<"\n";
		cout<<"Minimum Number of Trips = "<<t/adj[s][d]+((t%adj[s][d]==0)?0:1)<<"\n\n";
	}
	
	return 0;
}
