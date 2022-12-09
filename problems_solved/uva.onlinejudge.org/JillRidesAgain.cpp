/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=448
        Name: Jill Rides Again 
        Number: 507
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

int r, s[20005], mx, imx, jmx, sum, start;

int main () {
	ios_base::sync_with_stdio(0);
	int t, i, j;
	
	cin>>t;
	for (int it=1; it<=t; it++) {
		cin>>r;
		for (i=1; i<r; i++)
			cin>>s[i];
		mx = -1; sum = 0; start = 1;
		for (i=1; i<r; i++) {
			sum += s[i];
			if (sum < 0) {
				sum = 0;
				start = i+1;
			} else if (sum > mx) {
				mx = sum;
				imx = start;
				jmx = i+1;
			} else if (sum == mx) {
				if (i+1-start > jmx-imx) {
					imx = start;
					jmx = i+1;
				}
			}
		}
		if (mx >= 0) cout<<"The nicest part of route "<<it<<" is between stops "<<imx<<" and "<<jmx<<endl;
		else cout<<"Route "<<it<<" has no nice parts"<<endl;
	}
	
	return 0;
}
