/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2740
        Name: Coco-Bits and the Water
        Date: 26/12/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 1000000007ll
//#define MAXN 1000005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int k, t, x, y, r, ans, *cost;
vector<int> *graph;

void dfs (int idx) {
	if (cost[idx] > ans) ans = cost[idx];
	int aux = (int)graph[idx].size() + cost[idx];
	for (int i=0; i<(int)graph[idx].size(); i++) {
		cost[graph[idx][i]] = aux;
		dfs(graph[idx][i]);
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>k>>t;
	graph = new vector<int>[k+1];
	cost = new int[k+1];
	for (i=0; i<t; i++) {
		cin>>x>>y;
		graph[x].push_back(y);
	}
	cin>>r;
	cost[r] = 0; ans = -1;
	dfs(r);
	cout<<ans<<endl;
	bool first = true;
	for (i=1; i<=k; i++) {
		if (cost[i] == ans) {
			if (first) {
				cout<<i;
				first = false;
			} else {
				cout<<" "<<i;
			}
		}
	}
	cout<<endl;
	
	return 0;
}
