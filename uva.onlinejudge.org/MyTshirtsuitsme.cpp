/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1986
        Name: My T-shirt suits me
        Number: 11045
        Date: 15/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 131071
//#define MAXN 10000010

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, m, f, res[120][120], dis[120], p[120];
vector<ii> graph[120]; //0 source ; 1 sink ; 2-7 T-shirts ; 8-120 volunteers
map<string, int> sizes;
string s1, s2;

void init () {
	sizes["XS"] = 2;
	sizes["S"] = 3;
	sizes["M"] = 4;
	sizes["L"] = 5;
	sizes["XL"] = 6;
	sizes["XXL"] = 7;
}

void augment (int v, int minEdge) {
	if (v == 0) { 
		f = minEdge;
	} else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f; 
		res[v][p[v]] += f; 
	} 
}
int edmonds_karp () {
	int mf, i, j, act;
	memset(res, 0, sizeof res);
	for (i=0; i<=m+7; i++) {
		for (j=0; j<(int)graph[i].size(); j++) {
			res[i][graph[i][j].first] = graph[i][j].second;
		}
	}
	mf = 0;
	while (true) {
		f = 0;
		for (i=0; i<=m+7; i++) {
			dis[i] = INF;
			p[i] = -1;
		}
		dis[0] = 0;
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			act = q.front();
			q.pop();
			if (act == 1) break;
			for (i=0; i<=m+7; i++) {
				if (res[act][i] > 0 && dis[i] == INF) {
					dis[i] = dis[act] + 1;
					q.push(i);
					p[i] = act;
				}
			}
		}
		augment(1, INF);
		if (f == 0) break;
		mf += f;
	}
	return mf;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC = 1, i, j;
	
	init();
	cin>>TC;
	while (TC--) {
		cin>>n>>m;
		for (i=2; i<=7; i++) {
			graph[i].clear();
			graph[i].push_back(ii(1, n/6));
		}
		graph[0].clear();
		for (i=8; i<=m+7; i++) {
			graph[0].push_back(ii(i, 1));
			cin>>s1>>s2;
			graph[i].clear();
			graph[i].push_back(ii(sizes[s1], 1));
			graph[i].push_back(ii(sizes[s2], 1));
		}
		if (edmonds_karp() == m) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}
