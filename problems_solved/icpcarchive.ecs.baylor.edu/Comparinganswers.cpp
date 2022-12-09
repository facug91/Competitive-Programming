/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2957
        Name: Comparing answers
        Date: 05/05/2015
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
typedef pair<ii, ii> iiii;
typedef vector<int> vi;    typedef vector<ii> vii;

struct Matrix {
	int mat[1005][1005];
};

int n;
Matrix a, b, c, d, e;

bool check () {
	int tc, i, j, k;
	for (tc=0; tc<10; tc++) {
		for (i=0; i<n; i++) c.mat[i][0] = (rand()%2);
		for (i=0; i<n; i++)
			for (d.mat[i][0] = k = 0; k<n; k++)
				d.mat[i][0] += a.mat[i][k] * c.mat[k][0];
		for (i=0; i<n; i++)
			for (e.mat[i][0] = k = 0; k<n; k++)
				e.mat[i][0] += b.mat[i][k] * c.mat[k][0];
		for (i=0; i<n; i++)
			for (c.mat[i][0] = k = 0; k<n; k++)
				c.mat[i][0] += a.mat[i][k] * d.mat[k][0];
		for (i=0; i<n; i++) if (e.mat[i][0] != c.mat[i][0]) return false;
	}
	return true;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(4); cerr<<fixed<<setprecision(10); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	srand(time(0));
	while (cin>>n, n) {
		for (i=0; i<n; i++) for (j=0; j<n; j++) cin>>a.mat[i][j];
		for (i=0; i<n; i++) for (j=0; j<n; j++) cin>>b.mat[i][j];
		if (check()) cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}
