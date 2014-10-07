/*
        By: facug91
        From: http://www.spoj.com/problems/TAP2014H/
        Name: Rush hour
        Number: 21175
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

int n, train[100005];
set<int> turns;
set<int>::iterator itr;

int solve () {
	turns.clear();
	turns.insert(train[0]);
	for (int i=1; i<n; i++) {
		itr = turns.upper_bound(train[i]);
		if (itr == turns.begin()) {
			turns.insert(train[i]);
		} else {
			turns.erase(--itr);
			turns.insert(train[i]);
		}
	}
	return (int)turns.size();
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n;
		for (i=0; i<n; i++) {
			cin>>train[i];
		}
		cout<<solve()<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
