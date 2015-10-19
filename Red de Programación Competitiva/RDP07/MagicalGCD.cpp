/*
        By: facug91
        From: https://acm.javeriana.edu.co/maratones/2015/07
        Name: Magical GCD
        Date: 08/08/2015
*/

#include <bits/stdc++.h>

using namespace std;
#define prev d392rhbcdgausidhdsadasda

typedef long long ll;

ll n, a[100005], ans, g, c, l;
map<ll, ll> prev, curr;

ll gcd (ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	int tc, i, j;
	
	cin>>tc;
	while (tc--) {
		cin>>n;
		for (i=0; i<n; i++) cin>>a[i];
		ans = 1ll;
		prev.clear();
		for (i=0; i<n; i++) {
			curr.clear();
			for (auto it : prev) {
				g = gcd(a[i], it.first);
				l = it.second+1ll;
				c = (it.second+1ll)*g;
				if (curr.find(g) == curr.end()) {
					curr[g] = l;
					ans = max(c, ans);
				} else {
					if (curr[g] < l) {
						curr[g] = l;
						ans = max(c, ans);
					}
				}
			}
			g = a[i];
			l = 1ll;
			c = a[i];
			if (curr.find(g) == curr.end()) {
				curr[g] = l;
				ans = max(c, ans);
			} else {
				if (curr[g] < l) {
					curr[g] = l;
					ans = max(c, ans);
				}
			}
			prev = curr;
		}
		cout<<ans<<endl;
	}
	
}

