/*
        By: facug91
        From: http://www.spoj.com/problems/KQUERYO/
        Name: K-Query Online
        Date: 05/10/2016
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
//#define MOD 1000000007ll
//#define MAXN 100000005

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n, m, a[30005], l, r, k, last_ans;
vi segtree[4*30005];

void build (int idx, int l, int r) {
	//if (l > r) return;
	if (l+1 == r) {
		segtree[idx].clear();
		segtree[idx].push_back(a[l]);
		return;
	}
	build(idx*2, l, (l+r)/2);
	build(idx*2+1, (l+r)/2, r);
	segtree[idx].resize(r-l);
	copy(a+l, a+r, segtree[idx].begin());
	sort(segtree[idx].begin(), segtree[idx].end());
}

// query = ¿cuántos hay menores o iguales a 'mid'?
int query (int idx, int l, int r, int i, int j, int k) {
	if (r <= i || j <= l) return 0;
	if (i <= l && r <= j) {
		return distance(segtree[idx].begin(), upper_bound(segtree[idx].begin(), segtree[idx].end(), k));
	}
	return query(idx*2, l, (l+r)/2, i, j, k) + query(idx*2+1, (l+r)/2, r, i, j, k);
}


int main () {
	//#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	//#endif
	//cout<<fixed<<setprecision(6); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>n;
	for (i=0; i<n; i++) cin>>a[i];
	build(1, 0, n);
	cin>>m;
	last_ans = 0;
	while (m--) {
		cin>>l>>r>>k;
		l ^= last_ans;
		r ^= last_ans;
		k ^= last_ans;
		if (l < 1) l = 1;
		if (r > n) r = n;
		if (l > r) last_ans = 0;
		else last_ans = r - l + 1 - query(1, 0, n, l-1, r, k);
		cout<<last_ans<<endl;
	}
	
	return 0;
}
