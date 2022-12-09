/*
        By: facug91
        From: http://acm.tju.edu.cn/toj/showp1779.html
        Name: Tri Tiling
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

int n, F[35], D[35];

int f (int idx);
int d (int idx);

int d (int idx) {
	if (D[idx] != -1) return D[idx];
	if (idx >= n) return 0;
	return D[idx] = f(idx+2) + d(idx+2);
}

int f (int idx) {
	if (F[idx] != -1) return F[idx];
	if (idx > n) return 0;
	if (idx == n) return 1;
	return F[idx] = 3 * f(idx+2) + 2 * d(idx+2);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>n, n != -1) {
		memset(D, -1, sizeof D);
		memset(F, -1, sizeof F);
		cout<<f(0)<<endl;
	}
	
	return 0;
}
