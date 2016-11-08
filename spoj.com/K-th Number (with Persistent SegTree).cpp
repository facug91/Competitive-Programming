/*
        By: facug91
        From: http://www.spoj.com/problems/MKTHNUM/
        Name: K-th Number (with Persistent SegTree)
        Date: 27/10/2016
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

int NEXT_FREE_INDEX;
int n, q, u, v, k, a[100005], RM[100005], ST[3000005], L[3000005], R[3000005], root[3000005];
map<int, int> M;

void build (int idx, int l, int r) {
	if (l+1 == r) {
		ST[idx] = 0;
		return;
	}
	int m = (l+r)/2;
	L[idx] = NEXT_FREE_INDEX++;
	R[idx] = NEXT_FREE_INDEX++;
	build(L[idx], l, m);
	build(R[idx], m, r);
	ST[idx] = ST[L[idx]] + ST[R[idx]];
} 

int insert (int idx, int l, int r, int v) {
	//cerr<<"idx "<<idx<<" l "<<l<<" r "<<r<<" v "<<v<<endl;
	if (l <= v && v < r) {
		if (l+1 == r) {
			ST[NEXT_FREE_INDEX] = 1;
			return NEXT_FREE_INDEX++;
		}
		int curr_index = NEXT_FREE_INDEX++;
		ST[curr_index] = ST[idx];
		L[curr_index] = L[idx];
		R[curr_index] = R[idx];
		int m = (l+r)/2;
		if (v < m) L[curr_index] = insert(L[idx], l, m, v);
		else R[curr_index] = insert(R[idx], m, r, v);
		ST[curr_index] = ST[L[curr_index]] + ST[R[curr_index]];
		return curr_index;
	}
	return idx;
}

int query (int a, int b, int l, int r, int k) {
	if (l+1 == r) return l;
	int m = (l+r)/2;
	int count = ST[L[b]] - ST[L[a]];
	if (count < k) return query(R[a], R[b], m, r, k-count);
	return query(L[a], L[b], l, m, k);
}

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(6); //cerr<<fixed<<setprecision(3); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5)
	int tc = 1, i, j;
	
	cin>>n>>q;
	for (i=1; i<=n; i++) {
		cin>>a[i];
		M[a[i]];
	}
	int idx = 0;
	for (auto it=M.begin(); it!=M.end(); it++) {
		//cerr<<it->F<<" "<<it->S<<" "<<idx<<endl;
		it->S = idx;
		RM[idx] = it->F;
		idx++;
		//cerr<<it->F<<" "<<it->S<<" "<<idx<<endl;
	}
	memset(ST, 0, sizeof ST);
	memset(L, -1, sizeof L);
	memset(R, -1, sizeof R);
	NEXT_FREE_INDEX = 1;
	build(0, 0, idx);
	root[0] = 0;
	for (i=1; i<=n; i++) {
		root[i] = insert(root[i-1], 0, idx, M[a[i]]);
		//cerr<<"ST["<<root[i]<<"] "<<ST[root[i]]<<endl;
		int xx;
	}
	while (q--) {
		cin>>u>>v>>k;
		cout<<RM[query(root[u-1], root[v], 0, idx, k)]<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
