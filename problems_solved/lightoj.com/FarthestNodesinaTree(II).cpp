/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1257
        Name: Farthest Nodes in a Tree (II)
        Date: 08/01/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int n, u, v, w;
vector<iii> tree[30005];
bool checked[30005];

struct cmp {
	bool operator() (const iii &a, const iii &b) {
		return a.second.second>b.second.second;
	}
};

int dfs (int idx, int father) {
	if (checked[idx]) {
		if (tree[idx][0].first != father) return tree[idx][0].second.second;
		else if (tree[idx].size() == 1) return 0;
		else return tree[idx][1].second.second;
	}
	int ans = 0;
	for (int i=0; i<(int)tree[idx].size(); i++) {
		if (tree[idx][i].first != father) {
			if (tree[idx][i].second.second == 0)
				tree[idx][i].second.second = dfs(tree[idx][i].first, idx)+tree[idx][i].second.first;
			ans = max(ans, tree[idx][i].second.second);
		}
	}
	return ans;
}

int main () {
	//ios_base::sync_with_stdio(0);
	int TC, i, j, k;
	
	scanf("%d", &TC);
	for (int it=1; it<=TC; it++) {
		scanf("%d", &n);
		for (i=0; i<n; i++) {
			tree[i].clear();
			checked[i] = false;
		}
		for (i=1; i<n; i++) {
			scanf("%d %d %d", &u, &v, &w);
			tree[u].push_back(iii(v, ii(w, 0)));
			tree[v].push_back(iii(u, ii(w, 0)));
		}
		printf("Case %d:\n", it);
		for (i=0; i<n; i++) {
			printf("%d\n", dfs(i, -1));
			sort(tree[i].begin(), tree[i].end(), cmp());
			checked[i] = true;
		}
	}
	
	return 0;
}
