/*
        By: facug91
        From: http://www.spoj.com/problems/SAMER08A/
        Name: Almost Shortest Path
        Number: 3405
        Date: 14/10/2014
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
const double PI = 2.0*acos(0.0);

#define INF 1000000000
//#define MOD 131071
//#define MAXN 10000010

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

struct cmp {
	bool operator()(const ii &a, const ii &b) {
		return a.second > b.second;
	}
};

int n, m, s, d, u, v, w, dis[2][505];
vector<ii> graph[2][505];
priority_queue<ii, vector<ii>, cmp> pq;
queue<int> q;
bool vis[505];

void dijkstra (int idx) {
	int i, j;
	for (i=0; i<n; i++) {
		dis[idx][i] = INF;
		vis[i] = false;
	}
	dis[idx][s] = 0;
	pq.push(ii(s, 0));
	ii act;
	while (!pq.empty()) {
		act = pq.top();
		pq.pop();
		if (!vis[act.first]) {
			vis[act.first] = true;
			for (i=0; i<(int)graph[idx][act.first].size(); i++) {
				if (graph[idx][act.first][i].second >= 0) {
					if (dis[idx][graph[idx][act.first][i].first] > dis[idx][act.first] + graph[idx][act.first][i].second) {
						dis[idx][graph[idx][act.first][i].first] = dis[idx][act.first] + graph[idx][act.first][i].second;
						pq.push(ii(graph[idx][act.first][i].first, dis[idx][graph[idx][act.first][i].first]));
					}
				}
			}
		}
	}
}
void eliminate () {
	int i;
	q.push(s);
	memset(vis, 0, sizeof vis);
	vis[s] = true;
	int act;
	while (!q.empty()) {
		act = q.front();
		q.pop();
		for (i=0; i<(int)graph[0][act].size(); i++) {
			if (dis[0][act]+graph[0][act][i].second+dis[1][graph[0][act][i].first] == dis[0][d]) {
				graph[0][act][i].second = -1;
			}
			if (!vis[graph[0][act][i].first]) {
				vis[graph[0][act][i].first] = true;
				q.push(graph[0][act][i].first);
			}
		}
	}
}

int main () {
	ios_base::sync_with_stdio(0);
	int TC, i, j;
	
	while (cin>>n>>m, n || m) {
		for (i=0; i<n; i++) {
			graph[0][i].clear();
			graph[1][i].clear();
		}
		cin>>s>>d;
		for (i=0; i<m; i++) {
			cin>>u>>v>>w;
			graph[0][u].push_back(ii(v, w));
			graph[1][v].push_back(ii(u, w));
		}
		dijkstra(0);
		swap(s, d);
		dijkstra(1);
		swap(s, d);
		eliminate();
		dijkstra(0);
		if (dis[0][d] == INF) cout<<"-1"<<endl;
		else cout<<dis[0][d]<<endl;
	}
	
	return 0;
}
