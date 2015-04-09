/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2259
        Name: Parentheses Arrangements
        Date: 07/03/2015
*/

#include <bits/stdc++.h>
#define EPS 1e-9
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl;
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

ll DP[1005];
int n;

pair<ll, ll> extended_euclid (ll a, ll b) {
	ll x = 0ll, lastx = 1ll;
	ll y = 1ll, lasty = 0ll;
	ll tmp;
	while (b != 0ll) {
		ll quotient = a/b;
		tmp = a; a = b; b = tmp%b;
		tmp = x; x = lastx - quotient*x; lastx = tmp;
		tmp = y; y = lasty - quotient*y; lasty = tmp;
	}
	return pair<ll, ll>(lastx ,lasty);
}

ll inv (ll a, ll m) {
	pair<ll, ll> res = extended_euclid(a, m);
	return ((res.first % m) + m) % m;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int TC;
		
	DP[0] = 1ll;
	for (ll i=1; i<1005; i++) DP[(int)i] = (((DP[(int)i-1] * (2ll*i*(2ll*i-1ll))) % MOD) * (inv((i+1ll)*i, MOD))) % MOD;
	cin>>TC;
	while (TC--) {
		cin>>n;
		cout<<DP[n]<<"\n";
	}
	
	return 0;
}
