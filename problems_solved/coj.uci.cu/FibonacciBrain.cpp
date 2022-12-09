/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=3095
        Name: Fibonacci Brain
        Date: 01/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 10
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

struct Matrix {
	int mat[2][2];
};

Matrix mat_mul (Matrix a, Matrix b) {
	Matrix ans; int i, j, k;
	for (i=0; i<2; i++)
		for (j=0; j<2; j++)
			for (ans.mat[i][j] = k = 0; k<2; k++)
				ans.mat[i][j] = (ans.mat[i][j] + a.mat[i][k] * b.mat[k][j]) % MOD;
	return ans;
}

Matrix mat_mod_pow (Matrix b, ll p) {
	Matrix ans; int i, j;
	for (i=0; i<2; i++)
		for (j=0; j<2; j++)
			ans.mat[i][j] = (i == j);
	while (p) {
		if (p & 1ll) ans = mat_mul(ans, b);
		b = mat_mul(b, b);
		p >>= 1ll;
	}
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j, l;
	
	ll n;
	Matrix origin, ans;
	origin.mat[0][0] = 1;
	origin.mat[0][1] = 1;
	origin.mat[1][0] = 1;
	origin.mat[1][1] = 0;
	while (cin>>n) {
		ans = mat_mod_pow(origin, n);
		cout<<ans.mat[1][0]<<endl;
	}
	
	return 0;
}
