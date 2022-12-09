/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2927
	Name: Jorge's Party
	Number: 2927
	Date: 25/06/2014
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iterator>
#include <utility>
#include <list>
#include <stack>
#include <iomanip>
#include <bitset>

#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
#define _log2(x) log(x) * 1.44269504088896340736
//const long double PI = 2*acos(0);

#define INF 1000000000
//
using namespace std;

int n, m, x, y, color[1005];
bool visited[1005];
vector<int> graph[1005];
queue<int> q; 

bool check_bipartite () {
	memset(visited, 0, sizeof visited);
	memset(color, 0, sizeof color);
	q.push(1); visited[1] = true;
	int act;
	while (!q.empty()) {
		act = q.front();
		q.pop();
		for (int i=0; i<graph[act].size(); i++)
			if (!visited[graph[act][i]]) {
				visited[graph[act][i]] = true;
				color[graph[act][i]] = (color[act]+1)%2;
				q.push(graph[act][i]);
			} else if (color[graph[act][i]] == color[act])
				return false;
	}
	return true;
}

int main() {
	
	scanf("%d %d", &n, &m);
	
	for (int i=0; i<m; i++) {
		scanf("%d %d", &x, &y);
		if (x != y) {
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
	}
	
	if (check_bipartite()) printf("YES\n");
	else printf("NO\n");
	
	return 0;
}
