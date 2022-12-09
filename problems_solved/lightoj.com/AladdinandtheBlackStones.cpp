/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1343
        Name: Aladdin and the Black Stones
        Date: 10/07/2015
*/
 
#include <bits/stdc++.h>
#define y1 nd03dnqwuidg1odbnw9uddu0132d
#define EPS 1e-9
#define MP make_pair
#define DEB(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
#define MOD 4294967296ll
//#define MAXN 1001
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;


struct cmp {
	bool operator() (const pair<ll, ii> &a, const pair<ll, ii> &b) {
		if (a.first == b.first) return (a.second.second-a.second.first)>(b.second.second-b.second.first);
		return a.first<b.first;
	}
};

int n;
ll w[505], ft[505][505], ans, aux;
vector<pair<ll, ii> > val;

void update (int x, int y, ll v) {
	int y1;
	while (x <= n) {
		y1 = y;
		while (y1 <= n) {
			ft[x][y1] = (ft[x][y1] + v) % MOD;
			y1 += (y1 & (-y1));
		}
		x += (x & (-x));
	}
}

ll query2 (int x, int y) {
	int y1; ll ans = 0ll;
	while (x > 0) {
		y1 = y;
		while (y1 > 0) {
			ans = (ans + ft[x][y1]) % MOD;
			y1 -= (y1 & (-y1));
		}
		x -= (x & (-x));
	}
	return ans;
}

ll query (int l, int r) {
	if (l == r-1) return 0;
	int x1 = l, y1 = l, x2 = r, y2 = r;
	return ((MOD + ((MOD + ((query2(x2-1, y2-1) + query2(x1, y1)) % MOD) - query2(x2-1, y1)) % MOD) - query2(x1, y2-1)) % MOD);
}

int main () {
	int tc, i, j;
	
	scanf("%d", &tc);
	for (int it=1; it<=tc; it++) {
		scanf("%d", &n);
		for (i=1; i<=n; i++) scanf("%lld", &w[i]);
		val.clear();
		for (i=1; i<=n; i++) for (j=i+1; j<=n; j++) val.push_back(MP(w[i]+w[j], ii(i, j)));
		sort(val.begin(), val.end(), cmp());
		ans = 0ll;
		memset(ft, 0, sizeof ft);
		for (i=0; i<val.size(); i++) {
			aux = (query(val[i].second.first, val[i].second.second) + 1ll) % MOD;
			ans = (ans + aux) % MOD;
			update(val[i].second.first, val[i].second.second, aux);
		}
		printf("Case %d: %lld\n", it, ans);
	}
	
	return 0;
}
