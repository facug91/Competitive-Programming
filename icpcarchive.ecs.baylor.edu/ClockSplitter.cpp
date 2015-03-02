/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4418
        Name: Clock Splitter
        Date: 15/02/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
#define find asjkldhakjsdbsakjdb
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

ll n, t, i, j, l, r, lres, rres, res;

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	
	while (cin>>n, n) {
		t = (n * (n + 1ll) / 2ll);
		l = 1ll;
		r = t - 1ll;
		i = 0ll;
		j = 1ll;
		res = MAX_LONG;
		while (j < n) {
			l -= i;
			r += i;
			i++;
			while (j < n && l <= r) {
				j++;
				l += j;
				r -= j;
			}
			if (abs(t - l * 2ll) < abs(t - (l - j) * 2ll)) {
				if (res > abs(t - l * 2ll)) {
					res = abs(t - l * 2ll);
					lres = i;
					rres = j;
				}
			} else {
				if (res > abs(t - (l - j) * 2ll)) {
					res = abs(t - (l - j) * 2ll);
					lres = i;
					rres = j - 1ll;
				}
			}
		}
		cout<<lres<<" "<<rres<<endl;
	}
	
	return 0;
}
