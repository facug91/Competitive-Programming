/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2094
        Name: Blots on Paper
        Date: 25/10/2014
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

int n, m, cont, mx, di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
queue<ii> q;
char **graph;

bool check_pos (int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}
void bfs (int i, int j) {
	q.push(ii(i, j));
	graph[i][j] = '0';
	cont++;
	int p = 0;
	ii act;
	while (!q.empty()) {
		p++;
		act = q.front();
		q.pop();
		int x = act.first;
		int y = act.second;
		for (int d=0; d<4; d++) {
			int w = x + di[d];
			int z = y + dj[d];
			if (check_pos(w, z) && graph[w][z] == '1') {
				graph[w][z] = '0';
				q.push(ii(w, z));
			}
		}
	}
	if (p > mx) mx = p;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	scanf("%d %d", &n, &m);
	graph = new char *[n];
	for (i=0; i<n; i++)
	  graph[i] = new char[m];
	for (i=0; i<n; i++)
		scanf("%s", graph[i]);
	cont = mx = 0;
	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			if (graph[i][j] == '1')
				bfs(i, j);
	cout<<cont<<" "<<mx<<endl;
	
	return 0;
}
