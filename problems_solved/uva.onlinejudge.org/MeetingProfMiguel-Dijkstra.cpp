/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1112
	Name: Meeting Prof. Miguel...
	Number: 10171
	Date: 27/06/2014
	Using -> Dijkstra's Algorithm
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

int n, ans, dist[2]['Z'+1];
char pos[2];
bool visited['Z'+1];
vector<char> p_ans;
vector<pair<char, pair<int, char> > > graph['Z'+1];

struct cmp {
	bool operator() (const pair<int, char> &a, const pair<int, char> &b) {
		return (a.first > b.first);
	}
};

void dijkstra (int source) {
	priority_queue<pair<int, char>, vector<pair<int, char> >, cmp> pq;
	for (char c='A'; c<='Z'; c++) 
		dist[source][c] = INF, visited[c] = false;
	dist[source][pos[source]] = 0;
	char age = (source) ? 'M' : 'Y';
	pq.push(make_pair(0, pos[source]));
	pair<int, char> act;
	while (!pq.empty()) {
		act = pq.top();
		pq.pop();
		visited[act.second] = true;
		for (int i=0; i<graph[act.second].size(); i++) {
			if (graph[act.second][i].second.second == age) {
				if (!visited[graph[act.second][i].first]) {
					if (dist[source][graph[act.second][i].first] > graph[act.second][i].second.first + dist[source][act.second]) {
						dist[source][graph[act.second][i].first] = graph[act.second][i].second.first + dist[source][act.second];
						pq.push(make_pair(dist[source][graph[act.second][i].first], graph[act.second][i].first));
					}
				}
			}
		}
	}
}

int main () {
	
	int i, j, k, w;
	char a, d, u, v;
	
	while (scanf("%d", &n), n) {
		
		for (i=0; i<n; i++) {
			scanf(" %c %c %c %c %d", &a, &d, &u, &v, &w);
			graph[u].push_back(make_pair(v, make_pair(w, a)));
			if (d == 'B') graph[v].push_back(make_pair(u, make_pair(w, a)));
		}
		scanf(" %c %c", &pos[0], &pos[1]);
		
		dijkstra(0);
		dijkstra(1);
		
		ans = INF; p_ans.clear();
		for (i='A'; i<='Z'; i++) {
			if ((dist[0][i] != INF) && (dist[1][i] != INF)) {
				if ((dist[0][i] + dist[1][i]) < ans) {
					ans = dist[0][i] + dist[1][i];
					p_ans.clear();
					p_ans.push_back(i);
				} else if ((dist[0][i] + dist[1][i]) == ans)
					p_ans.push_back(i);
			}
		}
		
		if (ans == INF) printf("You will never meet.\n");
		else {
			printf("%d", ans);
			for (i=0; i<p_ans.size(); i++)
				printf(" %c", p_ans[i]);
			printf("\n");
		}
		
		for (i='A'; i<='Z'; i++)
			graph[i].clear();
	}
	
	return 0;
}
