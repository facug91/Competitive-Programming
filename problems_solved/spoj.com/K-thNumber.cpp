/*
        By: facug91
        From: http://www.spoj.com/problems/MKTHNUM/
        Name: K-th Number
        Date: 04/10/2016
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

int n, m, a[100005], l, r, k;
vi segtree[4*100005];

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

int binary_search (int l, int r, int k) {
	int lo = -1e9-1, hi = 1e9, mid;
	while (lo+1 < hi) {
		mid = (lo+hi)/2;
		if (query(1, 0, n, l, r, mid) >= k) hi = mid;
		else lo = mid;
	}
	return hi;
}

int main () {
	//#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	//#endif
	//cout<<fixed<<setprecision(6); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>n>>m;
	for (i=0; i<n; i++) cin>>a[i];
	build(1, 0, n);
	while (m--) {
		cin>>l>>r>>k;
		cout<<binary_search(l-1, r, k)<<endl;
	}
	
	return 0;
}
