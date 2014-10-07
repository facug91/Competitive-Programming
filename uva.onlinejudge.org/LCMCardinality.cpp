/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1833
        Name: LCM Cardinality
        Number: 10892
        Date: 22/09/2014
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
//#define MAXN 10000010

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n;
vector<int> div1, div2;

int gcd (int u, int v) {
	int t;
	while (v) {
		t = u;
		u = v;
		v = t % v;
	}
	return abs(u);
}

int lcm (int a, int b) {
	return (a/gcd(a, b))*b;
}

void calc_divisors () {
	int i, j, r = sqrt(n) + 1;
	div1.clear();
	div2.clear();
	div1.push_back(1);
	div2.push_back(n);
	for (i=2; (i<div2.back()) && (i<=r); i++) {
		if (n % i == 0) {
			div1.push_back(i);
			div2.push_back(n/i);
		}
	}
	if (div1.back() == div2.back()) div2.pop_back();
	while (div2.size() != 0) {
		div1.push_back(div2.back());
		div2.pop_back();
	}
}

int solve () {
	calc_divisors();
	int i, j, ans = 0;
	for (i=0; i<(int)div1.size(); i++) {
		for (j=i; j<(int)div1.size(); j++) {
			if (lcm(div1[i], div1[j]) == n)
				ans++;
		}
	}
	return ans;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>n, n)
		cout<<n<<" "<<solve()<<endl;
	
	return 0;
}

