/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=991
        Name: Hartals
        Number: 10050
        Date: 24/08/2014
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
//#define MAXN N

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, p, period[3655], hartal[105], ans;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n;
		for (i=0; i<=n; i++)
			period[i] = 0;
		cin>>p;
		for (i=0; i<p; i++)
			cin>>hartal[i];
		for (i=0; i<p; i++)
			for (j=hartal[i]; j<=n; j+=hartal[i])
				period[j] = 1;
		ans = 0;
		for (i=1; i<=n; i++)
			if (!(((i+1) % 7 == 0) || (i % 7 == 0)))
				ans += period[i];
		cout<<ans<<endl;
	}
	
	return 0;
}

