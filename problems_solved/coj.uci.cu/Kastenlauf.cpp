/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2501
        Name: Kastenlauf
        Date: 07/02/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
#define list askjdgisebwqdasbjdgbq
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, adj[105][105], p[105][2];

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j, k;
	
	cin>>TC;
	while (TC--) {
		cin>>n; n+=2;
		for (i=0; i<n; i++) cin>>p[i][0]>>p[i][1];
		for (i=0; i<n; i++)
			for (j=0; j<n; j++) 
				adj[i][j] = adj[j][i] = ((abs(p[i][0]-p[j][0]) + abs(p[i][1]-p[j][1]) <= 1000) ? (abs(p[i][0]-p[j][0]) + abs(p[i][1]-p[j][1])) : INF);
		for (k=0; k<n; k++)
			for (i=0; i<n; i++)
				for (j=0; j<n; j++)
					if (adj[i][k] + adj[k][j] < adj[i][j])
						adj[i][j] = adj[i][k] + adj[k][j];
		if (adj[0][n-1] == INF) cout<<"sad"<<endl;
		else cout<<"happy"<<endl;
	}
	
	return 0;
}
