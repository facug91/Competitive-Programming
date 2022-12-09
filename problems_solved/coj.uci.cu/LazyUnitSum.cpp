/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2948
        Name: Lazy Unit Sum
        Number: 2948
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

char s[1005];
int n, aux;

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	scanf("%d", &TC);
	while (TC--) {
		scanf("%s", s);
		n = 0;
		for (i=0; s[i]; i++)
			n += (s[i]-'0');
		while (n >= 10) {
			aux = 0;
			while (n) {
				aux += (n%10);
				n /= 10;
			}
			n = aux;
		}
		printf("%d\n", n);
	}
	
	return 0;
}

