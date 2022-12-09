/*
        By: facug91
        From: http://acm.tju.edu.cn/toj/showp3011.html
        Name: Tiling a Grid With Dominoes
        Date: 01/01/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int w, F[50], D[50], E[50];

int e (int idx);
int d (int idx);
int f (int idx);

int e (int idx) {
	if (E[idx] != -1) return E[idx];
	if (idx >= w) return 0;
	return E[idx] = f(idx+2) + e(idx+2);
}

int d (int idx) {
	if (D[idx] != -1) return D[idx];
	if (idx >= w) return 0;
	return D[idx] = f(idx+1) + d(idx+1);
}

int f (int idx) {
	if (F[idx] != -1) return F[idx];
	if (idx == w) return 1;
	if (idx > w) return 0;
	return F[idx] = f(idx+1) + 4 * f(idx+2) + 2 * d(idx+2) + e(idx+2);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>w;
		memset(E, -1, sizeof E);
		memset(D, -1, sizeof D);
		memset(F, -1, sizeof F);
		cout<<it<<" "<<f(0)<<endl;
	}
	
	return 0;
}
