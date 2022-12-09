/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4840
        Name: Help cupid
        Date: 17/12/2014
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

int n, t[1005], sum1, sum2;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>n) {
		for (i=0; i<n; i++)
			cin>>t[i];
		sort(t, t+n);
		sum1 = 0;
		for (i=0; i<n; i+=2)
			sum1 += abs(t[i+1] - t[i]);
		sum2 = 24 - abs(t[0] - t[n-1]);
		for (i=1; i<n-1; i+=2)
			sum2 += abs(t[i+1] - t[i]);
		cout<<min(sum1, sum2)<<endl;
	}
	
	return 0;
}
