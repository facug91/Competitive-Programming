/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2757
        Name: Expensive subway
        Date: 20/10/2014
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

int s, c, w, p[405], number_ds, ans;
map<string, int> to_idx;
char line[50], *word = new char[20];
string str1, str2;
vector<ii> graph[405];
vector<pair<int, ii> > edges;

int find_set (int i) {
	return (p[i] == i) ? i : p[i] = find_set(p[i]);
}
void union_set (int i, int j, int w) {
	int x = find_set(i);
	int y = find_set(j);
	if (x != y) {
		number_ds--;
		ans += w;
		p[x] = y;
	}
}
void kruskal () {
	int i, j;
	for (i=0; i<s; i++) p[i] = i;
	number_ds = s;
	ans = 0;
	edges.clear();
	for (i=0; i<s; i++)
		for (j=0; j<(int)graph[i].size(); j++)
			edges.push_back(make_pair(graph[i][j].second, ii(i, graph[i][j].first)));
	sort(edges.begin(), edges.end());
	for (i=0; i<(int)edges.size(); i++)
		union_set(edges[i].second.first, edges[i].second.second, edges[i].first);
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (scanf("%d %d", &s, &c), s || c) {
		to_idx.clear();
		for (i=0; i<s; i++) {
			scanf("%s", line);
			to_idx[string(line)] = i;
			graph[i].clear();
		}
		getchar();
		while (gets(line)) {
			word = strtok(line, " ");
			str1 = string(word);
			word = strtok(NULL, " ");
			if (word == NULL) break;
			str2 = string(word);
			word = strtok(NULL, " ");
			w = atoi(word);
			graph[to_idx[str1]].push_back(ii(to_idx[str2], w));
		}
		kruskal();
		if (number_ds == 1) cout<<ans<<endl;
		else cout<<"Impossible"<<endl;
	}
	
	return 0;
}
