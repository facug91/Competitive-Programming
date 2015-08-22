/*
        By: facug91
        From: http://www.spoj.com/problems/MATCHING/
        Name: Fast Maximum Matching
        Date: 14/01/2015
*/

#include <bits/stdc++.h>
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 1000000007ll
#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m, p, a, b, dist[MAXN], match[MAXN];
vector<int> ady[MAXN];

bool bfs () {
	int u, v, i;
	queue<int> q;
	for (i=1; i<=n; i++)
		if (!match[i]) dist[i] = 0, q.push(i);
		else dist[i] = -1;
	dist[0] = -1;
	while (!q.empty()) {
		u = q.front(); q.pop();
		for (i=0; i<(int)ady[u].size(); i++) {
			v = ady[u][i];
			if (dist[match[v]] == -1) {
				dist[match[v]] = dist[u] + 1;
				q.push(match[v]);
			}
		}
	}
	return dist[0] != -1;
}

bool dfs (int u) {
	if (u == 0) return true;
	int v, i;
	for (i=0; i<(int)ady[u].size(); i++) {
		v = ady[u][i];
		if (dist[match[v]] == dist[u] + 1 && dfs(match[v])) {
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}

int max_matching () {
	int mm = 0;
	while (bfs())
		for (int i=1; i<=n; i++)
			if (!match[i] && dfs(i))
				mm++;
	return mm;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>n>>m>>p;
	for (i=0; i<p; i++) {
		cin>>a>>b;
		ady[a].push_back(b+n);
	}
	cout<<max_matching()<<endl;
	
	return 0;
}
