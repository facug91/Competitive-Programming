/*
        By: facug91
        From: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=774&page=show_problem&problem=1658
        Name: Mint
        Date: 03/03/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
#define MOD 1000000007ll
#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, t, c[55], h[15], a, b, d, aux;
ii ans[15];

int gcd (int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int lcm (int a, int b) {
	return a / gcd(a, b) * b;
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(3); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j, k, l, m;
	
	while (cin>>n>>t, n || t) {
		for (i=0; i<n; i++) cin>>c[i];
		sort(c, c+n, greater<int>());
		for (i=0; i<t; i++) {
			cin>>h[i];
			ans[i].F = 0;
			ans[i].S = INF;
		}
		for (m=0; m<t; m++) {
			for (i=0; i<n; i++) {
				if (c[i] > ans[m].S) continue;
				for (j=i+1; j<n; j++) {
					a = lcm(c[j], c[i]);
					if (a > ans[m].S) continue;
					for (k=j+1; k<n; k++) {
						b = lcm(c[k], a);
						if (b > ans[m].S) continue;
						for (l=k+1; l<n; l++) {
							d = lcm(c[l], b);
							if (d > ans[m].S) continue;
							aux = d * (h[m] / d);
							ans[m].F = max(ans[m].F, aux);
							if (aux == h[m]) ans[m].S = aux;
							else ans[m].S = min(ans[m].S, aux+d);
						}
					}
				}
			}
		}
		for (i=0; i<t; i++) cout<<ans[i].F<<" "<<ans[i].S<<endl;
	}
	
	return 0;
}
