/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1030
        Name: Discovering Gold
        Number: 1030
        Date: 28/08/2014
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
//#define MAXN 6005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, cave[105];
double DP[105];

double dp (int idx) {
	if (DP[idx] != -1.0) return DP[idx];
	int size = min(7, n-idx);
	double ans = 0;
	for (int i=1; i<size; i++)
		ans += dp(idx+i);
	return DP[idx] = ans/((double)(size-1)) + ((double)cave[idx]);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cout.precision(9);
	cout<<fixed;
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>n;
		for (i=0; i<n; i++)
			cin>>cave[i];
		for (i=0; i<n-1; i++)
			DP[i] = -1.0;
		DP[n-1] = (double)cave[n-1];
		cout<<"Case "<<it<<": "<<dp(0)<<endl;
	}
	
	return 0;
}

