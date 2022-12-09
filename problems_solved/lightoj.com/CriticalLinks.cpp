/*
        By: facug91
        From: http://www.lightoj.com/volume_showproblem.php?problem=1026
        Name: Critical Links
        Number: 1026
        Date: 17/10/2014
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

int n, v, e, u, df_number[100005], low[100005], father[100005];
char num[100005];
vector<int> graph[100005];
set<ii> critical_links;
set<ii>::iterator itr;

void dfs (int idx) {
	int act;
	for (int i=0; i<(int)graph[idx].size(); i++) {
		act = graph[idx][i];
		if (df_number[act] == -1) {
			df_number[act] = df_number[idx] + 1;
			father[act] = idx;
			low[act] = df_number[idx] + 1;
			dfs(act);
			if (low[act] > df_number[idx]) {
				critical_links.insert(ii(min(act, idx), max(act, idx)));
			}
			low[idx] = min(low[idx], low[act]);
		} else {
			if (father[idx] != act) {
				low[idx] = min(low[idx], df_number[act]);
			}
		}
	}
}

int main() {
	int TC, i, j;
	
	scanf("%d", &TC);
	for (int it=1; it<=TC; it++) {
		scanf("%d", &n);
		getchar();
		for (i=0; i<n; i++) {
			graph[i].clear();
		}
		for (i=0; i<n; i++) {
			gets(num);
			v = atoi(strtok(num, " ()"));
			e = atoi(strtok(NULL, " ()"));
			for (j=0; j<e; j++) {
				u = atoi(strtok(NULL, " ()"));
				graph[v].push_back(u);
				graph[u].push_back(v);
			}
		}
		critical_links.clear();
		memset(df_number, -1, sizeof df_number);
		for (i=0; i<n; i++) {
			if (df_number[i] == -1) {
				father[i] = i;
				df_number[i] = 0;
				low[i] = 0;
				dfs(i);
			}
		}
		printf("Case %d:\n%d critical links\n", it, (int)critical_links.size());
		for (itr=critical_links.begin(); itr!=critical_links.end(); itr++) {
			printf("%d - %d\n", (*itr).first, (*itr).second);
		}
	}
	
	return 0;
}
