/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1475
        Name: Wavio Sequence
        Number: 10534
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

int n, seq[10005], LIS[10005], LDS[10005], ans, aux;

struct cmp {
	bool operator() (int i, int j) {
		return seq[i] < seq[j]; }
};
set<int, cmp> ls;
set<int, cmp>::iterator itr;

void lis () {
	int i, j;
	ls.clear();
	for (i=0; i<n; i++) {
		LIS[i] = 1;
		itr = ls.lower_bound(i);
		if (itr == ls.end()) {
			LIS[i] = ls.size() + 1;
			ls.insert(i);
		} else if (seq[(*itr)] == seq[i]) {
			LIS[i] = LIS[(*itr)];
		} else {
			LIS[i] = LIS[(*itr)];
			ls.erase(itr);
			ls.insert(i);
		}
	}
}

void lds () {
	int i, j;
	ls.clear();
	for (i=n-1; i>=0; i--) {
		LDS[i] = 1;
		itr = ls.lower_bound(i);
		if (itr == ls.end()) {
			LDS[i] = ls.size() + 1;
			ls.insert(i);
		} else if (seq[(*itr)] == seq[i]) {
			LDS[i] = LDS[(*itr)];
		} else {
			LDS[i] = LDS[(*itr)];
			ls.erase(itr);
			ls.insert(i);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC = 1, i, j;
	
	while (cin>>n) {
		for (i=0; i<n; i++)
			cin>>seq[i];
		lis();
		lds();
		ans = 0;
		for (i=0; i<n; i++) {
			aux = min(LIS[i]-1, LDS[i]-1);
			aux = aux*2+1;
			ans = max(ans, aux);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

