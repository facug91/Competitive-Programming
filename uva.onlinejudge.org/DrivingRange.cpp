/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2957
        Name: Driving Range
        Date: 20/10/2014
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

int n, m, u, v, w, p[1000005], rank[1000005], number_ds, ans;
vector<ii> graph[1000005];
vector<pair<int, ii> > edges;

int find_set (int i) {
	return (p[i] == i) ? i : p[i] = find_set(p[i]);
}
void union_set (int i, int j, int w) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		number_ds--;
		ans = max(ans, w);
		if (rank[x] > rank[y]) {
			p[y] = x;
		} else {
			p[x] = y;
			if (rank[y] == rank[x]) rank[y]++;
		}
	}
}
void kruskal () {
	int i, j;
	for (i=0; i<n; i++) {
		p[i] = i;
		rank[i] = 0;
	}
	number_ds = n;
	ans = 0;
	edges.clear();
	for (i=0; i<n; i++)
		for (j=0; j<(int)graph[i].size(); j++)
			edges.push_back(make_pair(graph[i][j].second, ii(graph[i][j].first, i)));
	sort(edges.begin(), edges.end());
	ans = 0;
	for (i=0; i<(int)edges.size(); i++)
		union_set(edges[i].second.first, edges[i].second.second, edges[i].first);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>n>>m, n || m) {
		for (i=0; i<n; i++) graph[i].clear();
		for (i=0; i<m; i++) {
			cin>>u>>v>>w;
			graph[u].push_back(ii(v, w));
		}
		kruskal();
		if (number_ds == 1) cout<<ans<<endl;
		else cout<<"IMPOSSIBLE"<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
