/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2624
        Name: Vacation
        Date: 03/11/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int m, n, d[55], ans, days;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>m>>n;
		for (i=0; i<n; i++)
			cin>>d[i];
		sort(d, d+n);
		days = ans = i = 0;
		while (i < n && days+d[i] <= m) {
			days += d[i++];
			ans++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
