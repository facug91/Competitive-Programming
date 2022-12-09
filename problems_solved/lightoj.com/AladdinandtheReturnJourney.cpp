/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1348
        Name: Aladdin and the Return Journey
        Date: 09/07/2015
*/
 
#include <bits/stdc++.h>
#define y1 nd03dnqwuidg1odbnw9uddu0132d
#define EPS 1e-9
#define MP make_pair
#define DEB(x) cerr << "#" << (#x) << ": " << (x) << endl
const double PI = 2.0*acos(0.0);
 
#define INF 1000000000
//#define MOD 4294967296ll
//#define MAXN 1001
 
using namespace std;
typedef long long ll;
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;		typedef vector<iii> viii;

int n, q, u, v, f, op, idx, value[30030], ft[60060], L[60060], E[60060], H[30030], RMQ[60060][16], N[30030];
vi tree[30030];

//Start Fenwick Tree
void update (int pos, int val) {
	for (; pos<=n*2+1; pos+=(pos&(-pos))) ft[pos] += val;
}
int query (int pos) {
	int ans = 0;
	for (; pos>0; pos-=(pos&(-pos))) ans += ft[pos];
	return ans;
}
//End Fenwick Tree

//Start LCA
void dfs (int u, int f, int depth) {
	int i, v;
	update(idx+1, value[u]);
	H[u] = idx;
	E[idx] = u;
	L[idx++] = depth;
	for (i=0; i<tree[u].size(); i++) {
		v = tree[u][i];
		if (v != f) {
			dfs(v, u, depth+1);
			E[idx] = u;
			L[idx++] = depth;
		}
	}
	N[u] = idx;
	update(idx+1, -value[u]);
}
void create_rmq_table () {
	int i, j, n2 = n*2;
	for (i=0; i<n2; i++) RMQ[i][0] = i;
	for (j=1; (1<<j)<=n2; j++) {
		for (i=0; i+(1<<j)-1<n2; i++) {
			if (L[RMQ[i][j-1]] <= L[RMQ[i+(1<<(j-1))][j-1]]) RMQ[i][j] = RMQ[i][j-1];
			else RMQ[i][j] = RMQ[i+(1<<(j-1))][j-1];
		}
	}
}
int rmq (int i, int j) {
	int k = (int)floor(log((double)j-i+1) / log(2.0));
	if (L[RMQ[i][k]] <= L[RMQ[j-(1<<k)+1][k]]) return RMQ[i][k];
	else return RMQ[j-(1<<k)+1][k];
}
int lca (int i, int j) {
	if (H[i] > H[j]) swap(i, j);
	return rmq(H[i], H[j]);
}
//End LCA

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	//cout<<fixed<<setprecision(7); cerr<<fixed<<setprecision(7); //cin.ignore(INT_MAX, ' '); //cout << setfill('0') << setw(5) << 25
	int tc, i, j;
	
	scanf("%d", &tc);
	for (int it=1; it<=tc; it++) {
		scanf("%d", &n);
		for (i=1; i<=n; i++) {
			tree[i].clear();
			scanf("%d", &value[i]);
		}
		for (i=0; i<n-1; i++) {
			scanf("%d %d", &u, &v); 
			u++; v++;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}
		memset(ft, 0, sizeof ft);
		idx = 0;
		dfs(1, -1, 0);
		create_rmq_table();
		scanf("%d", &q);
		printf("Case %d:\n", it);
		while (q--) {
			scanf("%d %d %d", &op, &u, &v);
			if (op == 0) { //query
				u++; v++;
				int auxii = lca(u, v);
				f = E[auxii];
				printf("%d\n", query(H[u]+1)+query(H[v]+1)+value[f]-2*query(H[f]+1));
			} else { //op == 1 //update
				u++;
				update(H[u]+1, v-value[u]);
				update(N[u]+1, -(v-value[u]));
				value[u] = v;
			}
		}
	}
	
	return 0;
}
