/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2847
        Name: Heavy Cycle Edges
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

int n, m, u, v, w, p[1005];
vector<pair<int, ii> > edges;
vector<int> ans;

int find_set (int i) {
	return (p[i] == i) ? i : p[i] = find_set(p[i]);
}
void union_set (int i, int j, int w) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		p[y] = x;
	} else {
		ans.push_back(w);
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>n>>m, n || m) {
		edges.clear();
		for (i=0; i<m; i++) {
			cin>>u>>v>>w;
			edges.push_back(make_pair(w, ii(u, v)));
		}
		sort(edges.begin(), edges.end());
		ans.clear();
		for (i=0; i<n; i++) p[i] = i;
		for (i=0; i<(int)edges.size(); i++)
			union_set(edges[i].second.first, edges[i].second.second, edges[i].first);
		if (ans.size() == 0) cout<<"forest"<<endl;
		else {
			cout<<ans[0];
			for (i=1; i<(int)ans.size(); i++)
				cout<<" "<<ans[i];
			cout<<endl;
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
