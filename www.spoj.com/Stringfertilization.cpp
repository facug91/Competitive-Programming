/*
        By: facug91
        From: http://www.spoj.com/problems/TAP2014F/
        Name: String fertilization
        Date: 16/12/2014
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

int n, t, c, p, f[10005][105], g[10005][105], act = 0, gact = 0;
string s;

bool cmp (int i, int j) {
	return s[i] < s[j];
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>n>>t;
	for (i=0; i<n; i++) {
		f[0][i] = i;
		g[0][i] = 0;
	}
	while (t--) {
		cin>>c>>s>>p;
		act = max(act - c, 0);
		act++;
		for (i=0; i<n; i++) {
			f[act][i] = f[act-1][i];
		}
		i = 0;
		for (j=1; j<n; j++) {
			if (g[act-1][j-1] != g[act-1][j]) {
				if (i+1 != j) {
					stable_sort(f[act]+i, f[act]+j, cmp);
					g[act][i] = ++gact;
					for (++i; i<j; i++) {
						if (s[f[act][i]] != s[f[act][i-1]]) {
							g[act][i] = ++gact;
						} else {
							g[act][i] = gact;
						}
					}
				} else {
					g[act][i] = ++gact;
				}
				i = j;
			}
		}
		if (i+1 != n) {
			stable_sort(f[act]+i, f[act]+n, cmp);
			g[act][i] = ++gact;
			for (++i; i<n; i++) {
				if (s[f[act][i]] != s[f[act][i-1]]) {
					g[act][i] = ++gact;
				} else {
					g[act][i] = gact;
				}
			}
		} else {
			g[act][i] = ++gact;
		}
		cout<<f[act][p-1]+1<<endl;
	}
	
	return 0;
}
