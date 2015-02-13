/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2012
        Name: Domino Art
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
//#define MAXN 100005

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;
typedef vector<int> vi;
typedef vector<ii> vii;

int r, c, n, m, mm, idx[65][65], dist[4000], match[4000], dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
string grid[65];
vector<int> ady[4000];

bool bfs () {
	queue<int> q;
	int u, v, i;
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
	mm = 0;
	memset(match, 0, sizeof match);
	while (bfs())
		for (int i=1; i<=n; i++)
			if (!match[i] && dfs(i))
				mm++;
	return mm;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC = 1, i, j, k;
	
	while (cin>>r>>c, r || c) {
		for (i=0; i<r; i++)
			cin>>grid[i];
		n = 0;
		for (i=0; i<r; i++)
			for (j=i%2; j<c; j+=2)
				if (grid[i][j] == '#') idx[i][j] = n++;
		m = 0;
		for (i=0; i<r; i++)
			for (j=(i+1)%2; j<c; j+=2)
				if (grid[i][j] == '#') idx[i][j] = m++;
		for (i=0; i<n+m+1; i++)
			ady[i].clear();
		int x, y;
		for (i=0; i<r; i++) {
			for (j=i%2; j<c; j+=2) {
				if (grid[i][j] == '#') {
					for (k = 0; k<4; k++) {
						x = i + dx[k];
						y = j + dy[k];
						if (x >= 0 && x < r && y >= 0 && y < c && grid[x][y] == '#')
							ady[idx[i][j]+1].push_back(idx[x][y]+1+n);
					}
				}
			}
		}
		max_matching();
		cout<<"Case "<<TC++<<": ";
		if (mm == n && mm == m) cout<<"Possible"<<endl;
		else cout<<"Impossible"<<endl;
	}
	
	return 0;
}
