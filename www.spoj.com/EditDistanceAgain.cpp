/*
        By: facug91
        From: http://www.spoj.com/problems/EDIT/
        Name: Edit Distance Again
        Number: 10537
        Date: 26/08/2014
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
//#define MAXN N

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int ans1, ans2;
string s;
bool p;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>s) {
		ans1 = 0;
		for (i=0, p=0; i<(int)s.length(); i++, p^=1)
			if ((s[i] >= 'A' && s[i] <= 'Z') == p) ans1++;
		ans2 = 0;
		for (i=0, p=1; i<(int)s.length(); i++, p^=1)
			if ((s[i] >= 'A' && s[i] <= 'Z') == p) ans2++;
		cout<<min(ans1, ans2)<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}

