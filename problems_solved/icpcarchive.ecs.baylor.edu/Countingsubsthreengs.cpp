/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4835
        Name: Counting substhreengs
        Date: 17/12/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

string s;
int res[1000005][3], n;
ll ans;

bool is_numeric (char c) {
	return (c >= '0' && c <= '9');
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>s) {
		ans = 0ll;
		res[0][0] = res[0][1] = res[0][2] = 0;
		for (i=1; i<=(int)s.length(); i++) {
			if (is_numeric(s[i-1])) {
				n = (s[i-1] - '0') % 3;
				res[i][n] = res[i-1][0] + 1;
				res[i][(n+1)%3] = res[i-1][1];
				res[i][(n+2)%3] = res[i-1][2];
				ans += (ll)res[i][0];
			} else {
				res[i][0] = res[i][1] = res[i][2] = 0;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
