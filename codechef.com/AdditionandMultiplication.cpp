/*
        By: facug91
        From: http://www.codechef.com/JULY15/problems/ADDMUL
        Name: Addition and Multiplication
        Date: 07/07/2015
*/
 
#include <bits/stdc++.h>
#define EPS 1e-9
#define MP make_pair
#define DEBUG(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 10000100
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

ll n, q, op, x, y, v, a[100005], st[4*100005], lazy_add[4*100005], lazy_mul[4*100005], lazy_ini[4*100005];

void create (int idx, ll l, ll r) {
	lazy_add[idx] = lazy_ini[idx] = 0ll;
	lazy_mul[idx] = 1ll;
	
	if (l == r) {
		st[idx] = a[l];
		return;
	}
	
	create(idx*2, l, (l+r)/2ll);
	create(idx*2+1, (l+r)/2ll+1ll, r);
	st[idx] = (st[idx*2] + st[idx*2+1]) % MOD;
}

void update (int idx, ll l, ll r, ll x, ll y, ll v) {
	
	if (lazy_ini[idx] != 0ll) {
		st[idx] = ((r-l+1ll) * lazy_ini[idx]) % MOD;
		if (l != r) {
			lazy_ini[idx*2] = lazy_ini[idx];
			lazy_ini[idx*2+1] = lazy_ini[idx];
			lazy_add[idx*2] = lazy_add[idx*2+1] = 0ll;
			lazy_mul[idx*2] = lazy_mul[idx*2+1] = 1ll;
		}
		lazy_ini[idx] = 0ll;
	}
	
	if (lazy_mul[idx] != 1ll) {
		st[idx] = (st[idx] * lazy_mul[idx]) % MOD;
		if (l != r) {
			lazy_mul[idx*2] = (lazy_mul[idx*2] * lazy_mul[idx]) % MOD;
			lazy_mul[idx*2+1] = (lazy_mul[idx*2+1] * lazy_mul[idx]) % MOD;
			lazy_add[idx*2] = (lazy_add[idx*2] * lazy_mul[idx]) % MOD;
			lazy_add[idx*2+1] = (lazy_add[idx*2+1] * lazy_mul[idx]) % MOD;
		}
		lazy_mul[idx] = 1ll;
	}
	
	if (lazy_add[idx] != 0ll) {
		st[idx] = (st[idx] + (r-l+1ll) * lazy_add[idx]) % MOD;
		if (l != r) {
			lazy_add[idx*2] = (lazy_add[idx*2] + lazy_add[idx]) % MOD;
			lazy_add[idx*2+1] = (lazy_add[idx*2+1] + lazy_add[idx]) % MOD;
		}
		lazy_add[idx] = 0ll;
	}
	
	if (l > y || r < x) return;
	
	if (x <= l && r <= y) {
		if (op == 3) {
			st[idx] = ((r-l+1ll) *  v) % MOD;
			if (l != r) {
				lazy_ini[idx*2] = v;
				lazy_ini[idx*2+1] = v;
				lazy_add[idx*2] = lazy_add[idx*2+1] = 0ll;
				lazy_mul[idx*2] = lazy_mul[idx*2+1] = 1ll;
			}
		} else if (op == 2) {
			st[idx] = (st[idx] * v) % MOD;
			if (l != r) {
				lazy_mul[idx*2] = (lazy_mul[idx*2] * v) % MOD;
				lazy_mul[idx*2+1] = (lazy_mul[idx*2+1] * v) % MOD;
				lazy_add[idx*2] = (lazy_add[idx*2] * v) % MOD;
				lazy_add[idx*2+1] = (lazy_add[idx*2+1] * v) % MOD;
			}
		} else {
			st[idx] = (st[idx] + (r-l+1ll) * v) % MOD;
			if (l != r) {
				lazy_add[idx*2] = (lazy_add[idx*2] + v) % MOD;
				lazy_add[idx*2+1] = (lazy_add[idx*2+1] + v) % MOD;
			}
		}
		return;
	}
	
	update(idx*2, l, (l+r)/2ll, x, y, v);
	update(idx*2+1, (l+r)/2ll+1ll, r, x, y, v);
	st[idx] = (st[idx*2] + st[idx*2+1]) % MOD;
}

ll query (int idx, ll l, ll r, ll x, ll y) {
	if (l > y || r < x) return 0ll;
	
	if (lazy_ini[idx] != 0ll) {
		st[idx] = ((r-l+1ll) * lazy_ini[idx]) % MOD;
		if (l != r) {
			lazy_ini[idx*2] = lazy_ini[idx];
			lazy_ini[idx*2+1] = lazy_ini[idx];
			lazy_add[idx*2] = lazy_add[idx*2+1] = 0ll;
			lazy_mul[idx*2] = lazy_mul[idx*2+1] = 1ll;
		}
		lazy_ini[idx] = 0ll;
	}
	
	if (lazy_mul[idx] != 1ll) {
		st[idx] = (st[idx] * lazy_mul[idx]) % MOD;
		if (l != r) {
			lazy_mul[idx*2] = (lazy_mul[idx*2] * lazy_mul[idx]) % MOD;
			lazy_mul[idx*2+1] = (lazy_mul[idx*2+1] * lazy_mul[idx]) % MOD;
			lazy_add[idx*2] = (lazy_add[idx*2] * lazy_mul[idx]) % MOD;
			lazy_add[idx*2+1] = (lazy_add[idx*2+1] * lazy_mul[idx]) % MOD;
		}
		lazy_mul[idx] = 1ll;
	}
	
	if (lazy_add[idx] != 0ll) {
		st[idx] = (st[idx] + (r-l+1ll) * lazy_add[idx]) % MOD;
		if (l != r) {
			lazy_add[idx*2] = (lazy_add[idx*2] + lazy_add[idx]) % MOD;
			lazy_add[idx*2+1] = (lazy_add[idx*2+1] + lazy_add[idx]) % MOD;
		}
		lazy_add[idx] = 0ll;
	}
	
	if (x <= l && r <= y) return st[idx];
	
	return (query(idx*2, l, (l+r)/2ll, x, y) + query(idx*2+1, (l+r)/2ll+1ll, r, x, y)) % MOD;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int i, j;
	
	cin>>n>>q;
	for (i=0; i<n; i++) cin>>a[i];
	create(1, 0ll, n-1ll);
	while (q--) {
		cin>>op>>x>>y;
		if (op <= 3) {
			cin>>v; x--; y--;
			update(1, 0ll, n-1ll, x, y, v);
		} else {
			x--; y--;
			cout<<query(1, 0ll, n-1ll, x, y)<<"\n";
		}
	}
	
	return 0;
}
