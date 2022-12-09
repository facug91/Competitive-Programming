/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2062
        Name: Base -2
        Number: 11121
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

int n, b2[1000], size;

void to_base_minus_2 () {
	size = 0;
	bool sign;
	while (n) {
		b2[size] = n % 2;
		n /= (-2);
		if (b2[size] < 0) {
			b2[size] = b2[size] + 2;
			n++;
		}
		size++;
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>n;
		if (n == 0) cout<<"Case #"<<it<<": 0"<<endl;
		else {
			to_base_minus_2();
			cout<<"Case #"<<it<<": ";
			for (i=size-1; i>=0; i--) {
				cout<<b2[i];
			}
			cout<<endl;
		}
	}
	
	return 0;
}

