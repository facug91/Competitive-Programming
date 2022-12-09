/*
        By: facug91
        From: http://coj.uci.cu/24h/problem.xhtml?pid=2081
        Name: Saving Money
        Date: 27/10/2014
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

int n, m, q, a, b, c, graph[105][105];

void floyd_warshall () {
	int i, j, k;
	for (k=1; k<=n; k++)
		for (i=1; i<=n; i++)
			for (j=1; j<=n; j++)
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	cin>>TC;
	while (TC--) {
		cin>>n>>m;
		for (i=1; i<=n; i++) {
			for (j=1; j<=n; j++)
				graph[i][j] = INF;
			graph[i][i] = 0;
		}
		for (i=0; i<m; i++) {
			cin>>a>>b>>c;
			if (graph[a][b] > c)
				graph[a][b] = graph[b][a] = c;
		}
		floyd_warshall();
		for (i=1; i<=n; i++)
			for (j=1; j<=n; j++)
				if (graph[i][j] == INF)
					graph[i][j] = -1;
		cin>>q;
		for (i=0; i<q; i++) {
			cin>>a>>b;
			cout<<graph[a][b]<<endl;
		}
		if (TC) cout<<endl;
	}
	
	return 0;
}
