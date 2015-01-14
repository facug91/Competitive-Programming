/*
        By: facug91
        From: http://www.spoj.com/problems/TAP2014I/
        Name: Stapled intervals
        Date: 16/12/2014
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

int criba[10000010], p, a, b, ans;
vector<ii> intervals;

void init () {
	int i, j;
	for (i=2; i<10000010; i++) {
		criba[i] = (i & 1) ? 0 : 2;
	}
	for (i=3; i<3170; i+=2) {
		if (!criba[i]) {
			criba[i] = i;
			for (j=i*i; j<10000010; j+=(i<<1)) {
				if (!criba[j]) {
					criba[j] = i;
				}
			}
		}
	}
	for (i=3171; i<10000010; i+=2) {
		if (!criba[i]) {
			criba[i] = i;
		}
	}
	
	int a, b;
	for (i=4; i<10000010; i++) {
		if (i == criba[i]) continue;
		a = i; b = i + criba[i];
		for (j=i+1; (criba[j]!=j) && (j<10000010); j++) {
			if (j > b) {
				if (a <= j - criba[j]) b = j;
				else b = j + criba[j];
			}
			if (b == j) {
				intervals.push_back(ii(a, b));
			} else if (!((a <= (j - criba[j])) || ((j + criba[j]) <= b))) {
				b = j + criba[j];
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	init();
	cin>>p;
	for (i=0; i<p; i++) {
		cin>>a>>b;
		ans = 0;
		for (j=0; j<(int)intervals.size(); j++) {
			if (intervals[j].first >= a && intervals[j].second <= b) ans++;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
