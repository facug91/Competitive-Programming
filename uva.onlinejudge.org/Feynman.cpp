/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3301
        Name: Feynman
        Number: 12149
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

int n, memo[105];

void init () {
	memo[1] = 1;
	for (int i=2; i<105; i++)
		memo[i] = memo[i-1] + i*i;
}

int main () {
	ios_base::sync_with_stdio(0);
	int i, j;
	
	init();
	
	while (cin>>n, n) 
		cout<<memo[n]<<endl;
	
	return 0;
}

