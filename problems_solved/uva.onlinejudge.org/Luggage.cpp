/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1605
        Name: Luggage
        Number: 10664
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

int n, w, l[25], DP[25][105];
char in[100], *p;

bool dp (int idx, int act) {
	if (act == w) return true;
	if (idx == n) return false;
	if (DP[idx][act] != -1) return DP[idx][act];
	if (act+l[idx] > w) return DP[idx][act] = dp(idx+1, act);
	bool ans = dp(idx+1, act);
	if (ans) return true;
	ans = dp(idx+1, act+l[idx]);
	if (ans) return true;
	DP[idx][act] = false;
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	scanf("%d", &TC);
	getchar();
	while (TC--) {
		gets(in);
		p = strtok(in, " ");
		n = w = 0;
		while (p != NULL) {
			w += l[n++] = atoi(p);
			p = strtok(NULL, " ");
		}
		if (w % 2 != 0) cout<<"NO"<<endl;
		else {
			w /= 2;
			memset(DP, -1, sizeof DP);
			if (dp(0, 0)) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	
	return 0;
}

