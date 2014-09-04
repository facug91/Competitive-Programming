/*
        By: facug91
        From: http://www.spoj.com/problems/ELIS/
        Name: Easy Longest Increasing Subsequence
        Code: ELIS
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

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int n, a[15], lis[15];

int LIS () {
	int i, j, mx = -1;
	for (i=0; i<n; i++) {
		lis[i] = 1;
		for (j=0; j<i; j++) {
			if ((a[j] < a[i]) && (lis[j]+1 > lis[i]))
				lis[i] = lis[j]+1;
		}
		if (lis[i] > mx) mx = lis[i];
	}
	return mx;
}

int main () {
	ios_base::sync_with_stdio(0);
	int i, j;
	
	cin>>n;
	for (i=0; i<n; i++)
		cin>>a[i];
	cout<<LIS()<<endl;
	
	return 0;
}
