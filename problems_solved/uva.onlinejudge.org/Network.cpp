/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=251
        Name: Network
        Number: 315
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

int n, u, v, df_number[105], low[105], father[105], ans;
char in[10500], *p = new char[105];
bool graph[105][105];

int dfs (int idx) {
	int sum = 0; bool critical = false;
	for (int i=1; i<=n; i++) {
		if (graph[idx][i] && father[idx] != i) {
			if (df_number[i] == -1) {
				df_number[i] = low[i] = df_number[idx]+1;
				father[i] = idx;
				sum += dfs(i);
				if (low[i] >= df_number[idx]) {
					critical = true;;
				}
				low[idx] = min(low[idx], low[i]);
			} else {
				low[idx] = min(low[idx], df_number[i]);
			}
		}
	}
	return sum+critical;
}

int dfs_main (int idx) {
	int cant = 0, sum = 0;
	df_number[idx] = 0;
	low[idx] = 0;
	for (int i=1; i<=n; i++) {
		if (graph[idx][i] && df_number[i] == -1) {
			cant++;
			df_number[i] = low[i] = 1;
			father[i] = idx;
			sum += dfs(i);
		}
	}
	if (cant > 1) sum++;
	return sum;
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (scanf("%d", &n), n) {
		memset(graph, 0, sizeof graph);
		getchar();
		while (gets(in), in[0] != '0') {
			p = strtok(in, " ");
			u = atoi(p);
			p = strtok(NULL, " ");
			while (p != NULL) {
				v = atoi(p);
				p = strtok(NULL, " ");
				graph[u][v] = graph[v][u] = true;
			}
		}
		ans = 0;
		memset(df_number, -1, sizeof df_number);
		memset(father, -1, sizeof father);
		for (i=1; i<=n; i++) {
			if (df_number[i] == -1) {
				ans += dfs_main(i);
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
