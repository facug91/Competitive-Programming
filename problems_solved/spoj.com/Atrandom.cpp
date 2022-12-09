/*
        By: facug91
        From: http://www.spoj.com/ranks/TAP2014A/
        Name: At random
        Number: 21168
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

int n;
pair<int, char> card[50];

bool check () {
	for (int i=1; i<n; i++) {
		if (card[i].first == card[i-1].first || card[i].second == card[i-1].second) {
			return false;
		}
	}
	return true;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n;
		for (i=0; i<n; i++) {
			cin>>card[i].first>>card[i].second;
		}
		if (check()) cout<<"B"<<endl;
		else cout<<"M"<<endl;
	}
	
	return 0;
}
