/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2966
	Name: Tiki-Taka
	Number: 2966
	Date: 16/07/2014
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iterator>
#include <utility>
#include <list>
#include <stack>
#include <iomanip>
#include <bitset>

#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
#define _log2(x) log(x) * 1.44269504088896340736
//const long double PI = 2*acos(0);

#define INF 1000000000
#define MOD 1000000007LL

using namespace std;

struct Matrix {long long mat[12][12];};

int p, l, a, b, q, x, y;
Matrix m, ans;
long long n;

Matrix matMul (Matrix a, Matrix b) {
	Matrix ans; int i, j, k;
	for (i=0; i<p; i++)
		for (j=0; j<p; j++)
			for (ans.mat[i][j] = k = 0; k<p; k++) 
				ans.mat[i][j] = (ans.mat[i][j] + ((a.mat[i][k] * b.mat[k][j]) % MOD)) % MOD;
	return ans;
}

Matrix matPow (Matrix base, long long n) {
	Matrix ans; int i, j;
	for (i=0; i<p; i++)
		for (j=0; j<p; j++)
			ans.mat[i][j] = (i == j);
	while (n) {
		if (n % 2 == 1) ans = matMul(ans, base);
		base = matMul(base, base);
		n /= 2;
	}
	return ans;
}

int main () {
	int t, i, j, k;
	
	scanf("%d", &t);
	
	for (int it=1; it<=t; it++) {
		
		scanf("%d %d", &p, &l);
		
		for (i=0; i<p; i++)
			for (j=0; j<p; j++)
				m.mat[i][j] = 0;
		
		for (i=0; i<l; i++) {
			scanf("%d %d", &a, &b);
			m.mat[a-1][b-1] = 1;
		}
		
		printf("Case %d:\n", it);
		
		scanf("%d", &q);
		
		for (i=0; i<q; i++) {
			scanf("%d %d %lld", &x, &y, &n);
			ans = matPow(m, n);
			printf("%lld\n", ans.mat[x-1][y-1]);
		}
		
		
	}
	
	return 0;
}
