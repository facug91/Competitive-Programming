/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=565
        Name: CD
        Date: 28/10/2014
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
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, t, tape[25], ans, mx;

void search (int idx, int sum, int bitmask) {
	if (idx == t) {
		if ((sum <= n) && (mx < sum)) {
			mx = sum;
			ans = bitmask;
		}
		return;
	}
	search(idx+1, sum, bitmask);
	search(idx+1, sum+tape[idx], bitmask|(1<<idx));
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>n) {
		cin>>t;
		for (i=0; i<t; i++)
			cin>>tape[i];
		mx = -1;
		search(0, 0, 0);
		for (i=0; i<t; i++)
			if (ans & (1<<i))
				cout<<tape[i]<<" ";
		cout<<"sum:"<<mx<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
