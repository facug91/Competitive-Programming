/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=499
        Name: Wormholes
        Number: 558
        Date: 09/10/2014
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
#define MOD 131071
//#define MAXN 10000010

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, m, x, y, t, dis[1005];
vector<ii> graph[1005];

bool Bellman_Ford () {
	int i, j, k;
	dis[0] = 0;
	for (k = 1; k<n; k++) {
		for (i=0; i<n; i++) {
			for (j=0; j<(int)graph[i].size(); j++) {
				if (dis[graph[i][j].first] > dis[i] + graph[i][j].second) {
					dis[graph[i][j].first] = dis[i] + graph[i][j].second;
				}
			}
		}
	}
	for (i=0; i<n; i++) {
		for (j=0; j<(int)graph[i].size(); j++) {
			if (dis[graph[i][j].first] > dis[i] + graph[i][j].second) {
				return false;
			}
		}
	}
	return true;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n>>m;
		for (i=0; i<n; i++) {
			graph[i].clear();
		}
		for (i=0; i<m; i++) {
			cin>>x>>y>>t;
			graph[x].push_back(ii(y, t));
		}
		if (!Bellman_Ford()) {
			cout<<"possible"<<endl;
		} else {
			cout<<"not possible"<<endl;
		}
	}
	
	return 0;
}
