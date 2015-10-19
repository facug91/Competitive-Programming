/*
        By: facug91
        From: http://www.spoj.com/problems/TAP2014B/
        Name: Balanced base-3
        Number: 21169
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

int n, b3[20];

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n; i = 0;
		while (n) {
			b3[i] = n % 3;
			n /= 3;
			i++;
		}
		for (j=0; j<i-1; j++) {
			if (b3[j] > 1) {
				b3[j] -= 3;
				b3[j+1]++;
			}
		}
		if (b3[i-1] > 1) {
			b3[i-1] -= 3;
			cout<<"+";
		}
		for (j=i-1; j>=0; j--) {
			if (b3[j] == 1) {
				cout<<"+";
			} else if (b3[j] == 0) {
				cout<<"0";
			} else {
				cout<<"-";
			}
		}
		cout<<endl;
	}
	
	return 0;
}
