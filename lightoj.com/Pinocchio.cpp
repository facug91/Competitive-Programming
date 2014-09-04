/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1241
        Name: Pinocchio
        Number: 1241
        Date: 16/08/2014
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

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int n, size[15], ans;

int main () {
	ios_base::sync_with_stdio(0);
	int t, i, j;
	
	size[0] = 2;
	
	cin>>t;
	for (int it=1; it<=t; it++) {
		cin>>n;
		for (i=1; i<=n; i++)
			cin>>size[i];
		ans = 0;
		for (i=1; i<=n; i++) {
			if (size[i] > size[i-1]) {
				ans += ((size[i]-size[i-1])/5) + (((size[i]-size[i-1])%5)!=0);
			}
		}
		cout<<"Case "<<it<<": "<<ans<<"\n";
	}
	
	return 0;
}
