/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2606
        Name: Attacking Rooks
        Date: 07/02/2015
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
typedef pair<int, int> ii; typedef pair<int, ii> iii;
typedef vector<int> vi;    typedef vector<ii> vii;

int n, pos[105][105], dist[20005], match[20005];
string mat[105];
vi adj[20005];

int bfs () {
	int i, j, u, v;
	queue<int> q;
	for (i=1; i<n; i++)
		if (!match[i]) dist[i] = 0, q.push(i);
		else dist[i] = -1;
	dist[0] = -1;
	while (q.size()) {
		u = q.front(); q.pop();
		for (i=0; i<adj[u].size(); i++) {
			v = adj[u][i];
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
	for (i=0; i<adj[u].size(); i++) {
		v = adj[u][i];
		if (dist[match[v]] == dist[u] + 1 && dfs(match[v])) {
			match[u] = v;
			match[v] = u;
			return true;
		}
	}
	dist[u] = -1;
	return false;
}

int max_matching () {
	int mm = 0;
	memset(match, 0, sizeof match);
	while (bfs())
		for (int i=1; i<n; i++)
			if (!match[i] && dfs(i))
				mm++;
	return mm;
}

int main () {
	ios_base::sync_with_stdio(0);
	//cout << fixed << setprecision(10);
	int TC, i, j, k;
	
	cin>>n;
	for (i=0; i<n; i++) cin>>mat[i];
	k = 1;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			if (mat[i][j] == '.') pos[i][j] = k;
			else if ((j > 0) && (mat[i][j-1] == '.')) k++;
		}
		k++;
	}
	for (j=0; j<n; j++) {
		for (i=0; i<n; i++) {
			if (mat[i][j] == '.') {
				adj[k].push_back(pos[i][j]); adj[pos[i][j]].push_back(k);
			} else if (i > 0 && mat[i-1][j] == '.') k++;
		}
		k++;
	}
	n = k;
	cout<<max_matching()<<endl;
	
	return 0;
}
