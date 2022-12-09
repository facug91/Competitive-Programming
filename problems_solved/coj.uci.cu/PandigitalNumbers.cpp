/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2564
        Name: Pandigital Numbers
        Date: 10/02/2015
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
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

ll n;

bool check () {
	if (n <= 1ll) return false;
	if (((1ll << __builtin_popcountll(n)) - 1ll) == n) return false;
	else return true;
}

int main () {
	//ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j;
	
	scanf("%d", &TC);
	while (TC--) {
		scanf("%d", &n);
		if (!check()) printf("NO\n");
		else printf("YES\n");
	}
	
	return 0;
}
