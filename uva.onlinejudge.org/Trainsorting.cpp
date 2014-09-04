/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2451
        Name: Trainsorting
        Number: 11456
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

int n, seq[2005], LIS[2005], LDS[2005], ans;

void lis () {
	int i, j;
	for (i=0; i<n; i++) {
		LIS[i] = 1;
		for (j=0; j<i; j++)
			if ((seq[j] < seq[i]) && (LIS[j]+1 > LIS[i]))
				LIS[i] = LIS[j]+1;
	}
}
void lds () {
	int i, j;
	for (i=0; i<n; i++) {
		LDS[i] = 1;
		for (j=0; j<i; j++)
			if ((seq[j] > seq[i]) && (LDS[j]+1 > LDS[i]))
				LDS[i] = LDS[j]+1;
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC = 1, i, j;
	bool first = true;
	
	cin>>TC;
	while (TC--) {
		cin>>n;
		for (i=0; i<n; i++)
			cin>>seq[i];
		reverse(seq, seq+n);
		lis();
		lds();
		ans = 0;
		for (i=0; i<n; i++)
			ans = max(ans, LIS[i]+LDS[i]-1);
		cout<<ans<<endl;
	}
	
	return 0;
}

