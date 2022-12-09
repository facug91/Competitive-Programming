/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=1552
        Name: Fibonacci Calculation
        Date: 11/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

struct Matrix {
	ll mat[2][2];
};

ll n, m;
Matrix origin, ansn, ansm;

Matrix mod_mat_mul (Matrix a, Matrix b) {
	Matrix ans; int i, j, k;
	for (i=0; i<2; i++)
		for (j=0; j<2; j++)
			for (ans.mat[i][j] = k = 0; k<2; k++)
				ans.mat[i][j] = (ans.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % MOD;
	return ans;
}

Matrix mod_mat_pow (Matrix base, ll p) {
	Matrix ans; int i, j;
	ans.mat[0][0] = 1ll;
	ans.mat[0][1] = 0ll;
	ans.mat[1][0] = 0ll;
	ans.mat[1][1] = 1ll;
	while (p) {
		if (p & 1ll) ans = mod_mat_mul(ans, base);
		base = mod_mat_mul(base, base);
		p >>= 1ll;
	}
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC, i, j;
	
	origin.mat[0][0] = 1ll;
	origin.mat[0][1] = 1ll;
	origin.mat[1][0] = 1ll;
	origin.mat[1][1] = 0ll;
	cin>>TC;
	while (TC--) {
		cin>>n>>m;
		if (n == 0ll) {
			ansm = mod_mat_pow(origin, m+1ll);
			cout<<(ansm.mat[0][0]+MOD-1ll)%MOD<<"\n";
		} else {
			ansn = mod_mat_pow(origin, n);
		ansm = mod_mat_pow(origin, m+1ll);
		cout<<((ansm.mat[0][0]-1ll)+MOD-(ansn.mat[0][0]-1ll)+MOD)%MOD<<"\n";
		}
	}
	
	return 0;
}
