/*
        By: facug91
        From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=39
        Name: Stacking Boxes
        Number: 103
        Date: 20/08/2014
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

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, pair<int, int> > iii;

int k, n, box[50][15], DP[50];
vector<int> graph[50];
bool first;

int compare (int a, int b) {
	if (a > b) return 1;
	if (a < b) return -1;
	return 0;
}
int compare_boxes (int i, int j) {
	int comp = compare(box[i][0], box[j][0]);
	if (comp == 0) return 0;
	for (int s=1; s<n; s++)
		if (compare(box[i][s], box[j][s]) != comp)
			return 0;
	return comp;
}

void make_graph () {
	int i, j, c;
	for (i=0; i<k; i++) {
		sort(box[i], box[i]+n);
		graph[i].clear();
	}
	for (i=0; i<k; i++) {
		for (j=i+1; j<k; j++) {
			c = compare_boxes(i, j);
			if (c == -1) graph[i].push_back(j);
			else if (c == 1) graph[j].push_back(i);
		}
	}	
}

int dfs (int idx) {
	if (DP[idx] != -1) return DP[idx];
	DP[idx];
	int next = idx, aux;
	DP[idx] = 0;
	for (int i=0; i<(int)graph[idx].size(); i++) {
		aux = dfs(graph[idx][i]);
		if (aux > DP[idx]) {
			DP[idx] = aux;
			next = graph[idx][i];
		}
	}
	graph[idx].clear();
	graph[idx].push_back(next);
	return ++DP[idx];
}

void print (int idx) {
	if (first) first = false;
	else printf(" ");
	printf("%d", idx+1);
	if (graph[idx][0] == idx) {
		printf("\n");
		return;
	}
	print(graph[idx][0]);
}

int main () {
	ios_base::sync_with_stdio(0);
	int i, j;
	
	while (scanf("%d %d", &k, &n) != EOF) {
		for (i=0; i<k; i++)
			for (j=0; j<n; j++)
				scanf("%d", &box[i][j]);
		make_graph();
		memset(DP, -1, sizeof DP);
		for (i=0; i<k; i++)
			if (DP[i] == -1)
				dfs(i);
		int idx, mx = -1;
		for (i=0; i<k; i++)
			if (DP[i] > mx) {
				mx = DP[i];
				idx = i;
			}
		printf("%d\n", mx);
		first = true;
		print(idx);
	}
	
	return 0;
}
