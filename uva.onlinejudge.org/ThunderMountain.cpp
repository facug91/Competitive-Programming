/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1744
        Name: Thunder Mountain
        Date: 23/04/2015
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

int n, pos[105][2];
double adj[105][105], aux, ans;

double dist (int i, int j) {
	return hypot(pos[i][0]-pos[j][0], pos[i][1]-pos[j][1]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout<<fixed<<setprecision(4); //cerr<<fixed<<setprecision(10); //cout.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j, k;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n;
		for (i=0; i<n; i++) cin>>pos[i][0]>>pos[i][1];
		for (i=0; i<n; i++) adj[i][i] = 0.0;
		for (i=0; i<n; i++) for (j=i+1; j<n; j++) 
			if ((aux = dist(i, j)) < 10.0+EPS) adj[i][j] = adj[j][i] = aux;
			else adj[i][j] = adj[j][i] = 1e9;
		for (k=0; k<n; k++)
			for (i=0; i<n; i++) 
				for (j=0; j<n; j++)
					adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
		bool imp = false; ans = -1e9;
		for (i=0; i<n; i++) for (j=i+1; j<n; j++) {
			if (fabs(adj[i][j]-1e9) < EPS) imp = true;
			ans = max(ans, adj[i][j]);
		}
		cout<<"Case #"<<it<<":\n";
		if (imp) cout<<"Send Kurdy\n\n";
		else cout<<ans<<"\n\n";
	}
	
	return 0;
}
