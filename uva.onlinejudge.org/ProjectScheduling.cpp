/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=393
        Name: Project Scheduling
        Date: 19/10/2014
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
#define MAXN 1000005
#define LOG 21

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int w['Z'+1], DP['Z'+1], ans;
char line[1000], *p=new char[50], v[5];
map<char, vector<char> > graph;
map<char, vector<char> >::iterator itr;

int dp (char idx) {
	if (DP[idx] != -1) return DP[idx];
	int ans = 0;
	for (int i=0; i<(int)graph[idx].size(); i++) {
		ans = max(ans, dp(graph[idx][i]));
	}
	return DP[idx] = ans+w[idx];
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	scanf("%d", &TC);
	getchar();
	gets(line);
	while (TC--) {
		graph.clear();
		while (gets(line)) {
			if (line[0] == 0) break;
			p = strtok(line, " ");
			strcpy(v, p);
			p = strtok(NULL, " ");
			w[v[0]] = atoi(p);
			p = strtok(NULL, " ");
			if (p != NULL) {
				for (i=0; p[i]; i++) {
					graph[p[i]].push_back(v[0]);
				}
			}
		}
		memset(DP, -1, sizeof DP);
		ans = 0;
		for (itr=graph.begin(); itr!=graph.end(); itr++) {
			if (DP[(*itr).first] == -1) {
				ans = max(ans, dp((*itr).first));
			}
		}
		printf("%d\n", ans);
		if (TC) printf("\n");
		for (itr=graph.begin(); itr!=graph.end(); itr++) {
			(*itr).second.clear();
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
