/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2750
        Name: sqrt log sin
        Number: 11703
        Date: 11/09/2014
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

int x[1000005], n;

void init () {
	x[0] = 1;
	double idx, s;
	for (int i=1; i<1000005; i++) {
		idx = (double) i;
		s = sin(idx);
		x[i] = (x[(int)floor(idx-sqrt(idx))] + x[(int)floor(log(idx))] + x[(int)floor(idx*s*s)]) % 1000000;
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	init();
	while (cin>>n, n != -1)
		cout<<x[n]<<endl;
	
	return 0;
}

