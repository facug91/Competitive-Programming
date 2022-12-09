/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?abb=1678
        Name: Smaller Perimeter
        Number: 1678
        Date: 27/08/2014
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
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, a, b, c, ans;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	ans = INF;
	cin>>n;
	while (n--) {
		cin>>a>>b>>c;
		if (a+b > c && a+c > b && b+c > a)
			ans = min(ans, a+b+c);
	}
	cout<<ans<<endl;
	
	return 0;
}

