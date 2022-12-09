/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=216
        Name: Vertex
        Number: 280
        Date: 30/08/2014
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
//#define MAXN 6005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, u, v, k;
vector<int> graph[105];
bool vis[105];
queue<int> q;

void bfs () {
	memset(vis, 0, sizeof vis);
	int i, j;
	for (i=0; i<(int)graph[u].size(); i++) {
		q.push(graph[u][i]);
		vis[graph[u][i]] = true;
	}
	int act;
	while (!q.empty()) {
		act = q.front();
		q.pop();
		for (i=0; i<(int)graph[act].size(); i++) {
			if (!vis[graph[act][i]]) {
				q.push(graph[act][i]);
				vis[graph[act][i]] = true;
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC = 1, i, j;
	
	while (cin>>n, n) {
		for (i=1; i<=n; i++)
			graph[i].clear();
		while (cin>>u, u)
			while (cin>>v, v)
				graph[u].push_back(v);
		cin>>k;
		while (k--) {
			cin>>u;
			bfs();
			int cont = 0;
			for (i=1; i<=n; i++)
				cont += !vis[i];
			cout<<cont;
			for (i=1; i<=n; i++)
				if (!vis[i])
					cout<<" "<<i;
			cout<<endl;
		}
	}
	
	return 0;
}

