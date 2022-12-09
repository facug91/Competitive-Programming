/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=721&page=show_problem&problem=2412
        Name: GCD
        Number: 11417
        Date: 23/09/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 10000010

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n;

int g () {
	int i, j, ans = 0;
	for (i=1; i<n; i++) {
		for (j=i+1; j<=n; j++) {
			ans += __gcd(i, j);
		}
	}
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>n, n)
		cout<<g()<<endl;
	
	return 0;
}

