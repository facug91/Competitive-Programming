/*
        By: facug91
        From: http://www.spoj.com/problems/TAP2014G/
        Name: Gallantry
        Number: 21174
        Date: 07/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 131071
//#define MAXN 10000010

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, p[1005], d[505], total_diff, ans, aux;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>n;
	for (i=0; i<n; i++) {
		cin>>p[i];
	}
	sort(p, p+n);
	total_diff = 0;
	for (i=0; i<n; i+=2) {
		d[i/2] = abs(p[i]-p[i+1]);
		total_diff += d[i/2];
	}
	if (total_diff == 0) {
		ans = -1;
	} else {
		sort(d, d+(n/2));
		ans = 0;
		total_diff -= d[0];
		aux = d[0];
		i = 1;
		while (total_diff > aux) {
			ans++;
			total_diff -= d[i];
			aux += d[i++];
		}
	}
	cout<<ans<<endl;
	
	
	
	
	
	
	
	
	
	return 0;
}
