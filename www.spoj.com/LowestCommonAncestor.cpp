/*
        By: facug91
        From: http://www.spoj.com/problems/LCA/
        Name: Lowest Common Ancestor
        Date: 27/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, m, q, u, v, r, e[2005], iact, l[2005], h[1005], DP[2005][11];
bool root[1005];
vector<int> tree[1005];

void dfs (int idx, int depth) {
	h[idx] = iact;
	e[iact] = idx;
	l[iact++] = depth;
	for (int i=0; i<(int)tree[idx].size(); i++) {
		dfs(tree[idx][i], depth+1);
		e[iact] = idx;
		l[iact++] = depth;
	}
}
void dp () {
	int i, j, size = n*2-1;
	for (i=0; i<size; i++)
		DP[i][0] = i;
	for (int j=1; (1<<j)<=size; j++) {
		for (int i=0; i+(1<<j)-1<size; i++) {
			if (l[DP[i][j-1]] < l[DP[i+(1<<(j-1))][j-1]]) DP[i][j] = DP[i][j-1];
			else DP[i][j] = DP[i+(1<<(j-1))][j-1];
		}
	}
}
int rmq (int i, int j) {
	int k = (int)floor(log((double)j-i+1) / log(2.0));
	if (l[DP[i][k]] <= l[DP[j-(1<<k)+1][k]]) return DP[i][k];
	else return DP[j-(1<<k)+1][k];
}
int lca (int i, int j) {
	if (i > j) swap(i, j);
	return e[rmq(i, j)];
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	for (int it=1; it<=TC; it++) {
		cin>>n;
		for (i=0; i<n; i++) {
			tree[i].clear();
			root[i] = true;
		}
		for (i=0; i<n; i++) {
			cin>>m;
			for (j=0; j<m; j++) {
				cin>>u;
				tree[i].push_back(u-1);
				root[u-1] = false;
			}
		}
		for (r=0; !root[r]; r++); //busco la raíz del árbol
		iact = 0;
		dfs(r, 0);
		dp();
		cout<<"Case "<<it<<":"<<endl;
		cin>>q;
		for (i=0; i<q; i++) {
			cin>>u>>v;
			cout<<lca(h[u-1], h[v-1]) + 1<<endl;
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
