/*
        By: facug91
        From: http://www.spoj.com/problems/KQUERY/
        Name: K-query
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

int n, m, a[30005], l, r, k, ans[200005], segtree[4*30005];
pair<ii, ii> queries[200005];
ii val[30005];

void build (int idx, int l, int r) {
	//if (l > r) return;
	if (l+1 == r) {
		segtree[idx] = 1;
		return;
	}
	build(idx*2, l, (l+r)/2);
	build(idx*2+1, (l+r)/2, r);
	segtree[idx] = segtree[idx*2] + segtree[idx*2+1];
}

int query (int idx, int l, int r, int i, int j) {
	if (r <= i || j <= l) return 0;
	if (i <= l && r <= j) return segtree[idx];
	return query(idx*2, l, (l+r)/2, i, j) + query(idx*2+1, (l+r)/2, r, i, j);
}

void update (int idx, int l, int r, int p) {
	if (p < l || r <= p) return;
	if (l == p && p+1 == r) {
		segtree[idx] = 0;
		return;
	}
	update(idx*2, l, (l+r)/2, p);
	update(idx*2+1, (l+r)/2, r, p);
	segtree[idx] = segtree[idx*2] + segtree[idx*2+1];
}

int main () {
	//#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	//#endif
	//cout<<fixed<<setprecision(6); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>n;
	for (i=0; i<n; i++) {
		cin>>a[i];
		val[i].F = a[i];
		val[i].S = i;
	}
	sort(val, val+n);
	build(1, 0, n);
	cin>>m;
	for (i=0; i<m; i++) {
		cin>>l>>r>>k;
		queries[i].F.F = k;
		queries[i].F.S = i;
		queries[i].S.F = l-1;
		queries[i].S.S = r;
	}
	sort(queries, queries+m);
	int curr = 0;
	for (i=0; i<m; i++) {
		while (curr < n && val[curr].F <= queries[i].F.F) update(1, 0, n, val[curr++].S);
		ans[queries[i].F.S] = query(1, 0, n, queries[i].S.F, queries[i].S.S);
	}
	for (i=0; i<m; i++) cout<<ans[i]<<endl;
	
	return 0;
}
