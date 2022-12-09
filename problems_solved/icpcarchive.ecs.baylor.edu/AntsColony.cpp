/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2806
        Name: Ants Colony
        Date: 28/10/2014
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

int n, a, len, h[100005], e[200005], l[200005], iact, RMQ[300005][18], q, s, t;
ll RSQ[100005];
vector<ii> tree[100005];

void dfs (int idx, int depth) {
	h[idx] = iact;
	e[iact] = idx;
	l[iact++] = depth;
	for (int i=0; i<(int)tree[idx].size(); i++) {
		RSQ[tree[idx][i].first] = RSQ[idx] + tree[idx][i].second;
		dfs(tree[idx][i].first, depth+1);
		e[iact] = idx;
		l[iact++] = depth;
	}
}
void make_rmq () {
	int i, j, n2 = n*2-1;
	for (i=0; i<n2; i++)
		RMQ[i][0] = i;
	for (j=1; (1<<j)<=n2; j++) {
		for (i=0; i+(1<<j)-1<n2; i++) {
			if (l[RMQ[i][j-1]] <= l[RMQ[i+(1<<(j-1))][j-1]]) RMQ[i][j] = RMQ[i][j-1];
			else RMQ[i][j] = RMQ[i+(1<<(j-1))][j-1];
		}
	}
}
int rmq (int i, int j) {
	int k = (int)floor(log((double)j-i+1) / log(2.0));
	if (l[RMQ[i][k]] <= l[RMQ[j-(1<<k)+1][k]]) return RMQ[i][k];
	else return RMQ[j-(1<<k)+1][k];
}
int lca (int i, int j) {
	if (h[i] > h[j]) swap(i, j);
	return rmq(h[i], h[j]);
}
ll dist (int i, int j) {
	int f = lca(i, j);
	return RSQ[i] + RSQ[j] - 2 * RSQ[e[f]];
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (scanf("%d", &n), n) {
		for (i=0; i<n; i++)
			tree[i].clear();
		for (i=1; i<n; i++) {
			scanf("%d %d", &a, &len);
			tree[a].push_back(ii(i, len));
		}
		iact = 0; RSQ[0] = 0;
		dfs(0, 0);
		make_rmq();
		scanf("%d", &q);
		scanf("%d %d", &s, &t);
		printf("%lld", dist(s, t));
		for (i=1; i<q; i++) {
			scanf("%d %d", &s, &t);
			printf(" %lld", dist(s, t));
		}
		printf("\n");
	}
	
	return 0;
}
