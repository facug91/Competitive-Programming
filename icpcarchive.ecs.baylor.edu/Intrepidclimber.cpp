/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4841
        Name: Intrepid climber
        Date: 18/12/2014
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

int n, f, a, b, c, l, cost_total[100005], cost_path[100005];
vector<ii> tree[100005];
bool friends[100005];

int dfs (int idx) {
	for (int i=0; i<(int)tree[idx].size(); i++) {
		dfs(tree[idx][i].first);
		if (friends[tree[idx][i].first]) {
			cost_total[idx] += (tree[idx][i].second + cost_total[tree[idx][i].first]);
			cost_path[idx] = max(cost_path[idx], cost_path[tree[idx][i].first] + tree[idx][i].second);
		}
	}
	if (cost_total[idx] != 0) friends[idx] = true;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>n>>f) {
		for (i=1; i<=n; i++) {
			tree[i].clear();
			friends[i] = false;
			cost_total[i] = cost_path[i] = 0;
		}
		for (i=1; i<n; i++) {
			cin>>a>>b>>c;
			tree[a].push_back(ii(b, c));
		}
		for (i=0; i<f; i++) {
			cin>>l;
			friends[l] = true;
		}
		dfs(1);
		cout<<cost_total[1]-cost_path[1]<<endl;
	}
	
	return 0;
}
