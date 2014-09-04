/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=293
        Name: Let Me Count The Ways
        Number: 357
        Date: 22/08/2014
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
#define MAXN 30005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, coin[] = {5, 10, 25, 50};
ll DP[MAXN];

void dp () {
	int i, j;
	for (i=0; i<MAXN; i++)
		DP[i] = 1;
	for (i=0; i<4; i++)
		for (j=coin[i]; j<MAXN; j++)
			DP[j] += DP[j-coin[i]];
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC = 1, i, j;
	
	dp();
	while (cin>>n) {
		if (DP[n] == 1) cout<<"There is only 1 way to produce "<<n<<" cents change."<<endl;
		else cout<<"There are "<<DP[n]<<" ways to produce "<<n<<" cents change."<<endl;
	}
	
	return 0;
}
