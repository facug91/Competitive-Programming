/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1117
        Name: Ocean Deep ! - Make it shallow !!
        Number: 10176
        Date: 03/10/2014
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

int ans;
string s, num;

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (getline(cin, s)) {
		num = s;
		while (s[(int)s.length() - 1] != '#') {
			getline(cin, s);
			num += s;
		}
		ans = 0;
		for (i=0; i<(int)num.length()-1; i++) {
			ans = ((ans * 2) % MOD + (num[i] - '0')) % MOD;
		}
		if (ans == 0) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

