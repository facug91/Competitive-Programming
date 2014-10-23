/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1753
        Name: Beat the Spread!
        Number: 10812
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

int s, d, a, b;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>s>>d;
		if (s < d) cout<<"impossible"<<endl;
		else {
			a = d; b = 0; s -= d;
			if (s % 2 != 0) cout<<"impossible"<<endl;
			else cout<<a + s/2<<" "<<b + s/2<<endl;
		}
	}
	
	return 0;
}
