/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3138
        Name: Transpose
        Date: 18/03/2015
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

int n, m;
char mat[105][105];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n>>m;
		for (i=0; i<n; i++) for (j=0; j<m; j++) cin>>mat[i][j];
		for (j=0; j<m; j++) {
			cout<<mat[0][j];
			for (i=1; i<n; i++) cout<<" "<<mat[i][j];
			cout<<"\n";
		}
	}
	
	return 0;
}
