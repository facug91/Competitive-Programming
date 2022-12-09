/*
        By: facug91
        From: https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3807
        Name: Hedge Mazes
        Number: 5796
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

int r, c, q, u, v, df_number[10005], low[10005], father[10005], p[10005], rank[10005];
vector<int> graph[10005];

int find_set (int i) {
	return (p[i] == i) ? i : (p[i] = find_set(p[i]));
}
void union_set (int i, int j) {
	int x = find_set(i);
	int y = find_set(j);
	if (y != x) {
		if (rank[x] > rank[y]) {
			p[y] = x;
		} else {
			p[x] = y;
			if (rank[y] == rank[x]) rank[y]++;
		}
	}
}

void dfs (int idx) {
	int i, act;
	for (i=0; i<(int)graph[idx].size(); i++) {
		act = graph[idx][i];
		if (df_number[act] == -1) {
			df_number[act] = df_number[idx]+1;
			low[act] = df_number[act];
			father[act] = idx;
			dfs(act);
			if (low[act] > df_number[idx]) {
				union_set(act, idx);
			}
			low[idx] = min(low[idx], low[act]);
		} else if (father[idx] != act) {
			low[idx] = min(low[idx], df_number[act]);
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>r>>c>>q, r || c || q) {
		for (i=1; i<=r; i++) {
			graph[i].clear();
			p[i] = i;
			rank[i] = 0;
			df_number[i] = -1;
		}
		for (i=0; i<c; i++) {
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		for (i=1; i<=r; i++) {
			if (df_number[i] == -1) {
				df_number[i] = 0;
				low[i] = 0;
				father[i] = i;
				dfs(i);
			}
		}
		for (i=0; i<q; i++) {
			cin>>u>>v;
			if (find_set(u) == find_set(v)) cout<<"Y"<<endl;
			else cout<<"N"<<endl;
		}
		cout<<"-"<<endl;
	}
	
	return 0;
}
