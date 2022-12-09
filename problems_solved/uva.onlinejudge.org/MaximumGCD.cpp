/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2927
        Name: Maximum GCD
        Number: 11827
        Date: 23/09/2014
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

int ans;
char in[5000];
vector<int> seq;

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	scanf("%d", &TC);
	getchar();
	while (TC--) {
		gets(in);
		char *p = new char[15];
		p = strtok(in, " ");
		while (p != NULL) {
			seq.push_back(atoi(p));
			p = strtok(NULL, " ");
		}
		ans = 1;
		for (i=0; i<(int)seq.size(); i++) {
			for (j=i+1; j<(int)seq.size(); j++) {
				ans = max(ans, __gcd(seq[i], seq[j]));
			}
		}
		cout<<ans<<endl;
		if (TC) seq.clear();
	}
	
	return 0;
}

