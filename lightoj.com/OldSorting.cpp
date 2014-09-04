/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1166
        Name: Old Sorting
        Number: 1166
        Date: 19/08/2014
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

int n, seq[105], ans;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>n;
		for (i=1; i<=n; i++)
			cin>>seq[i];
		ans = 0;
		for (i=1; i<=n; i++)
			if (seq[i] != i) {
				for (j=i+1; i!=seq[j]; j++);
				swap(seq[i], seq[j]);
				ans++;
			}
		cout<<"Case "<<it<<": "<<ans<<endl;
	}
	
	return 0;
}
