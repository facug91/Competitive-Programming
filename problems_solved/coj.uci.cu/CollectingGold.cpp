/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1868
	Name: Collecting Gold
	Number: 1868
	Date: 13/06/2014
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

int n, m;

//matriz inicial, mapa
char matrix[25][25];

//grafo de distancias ya armado
int graph[20][20];

//estructuras para ejecutar el bfs()
bool visited[405][405];
int dist1[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dist2[] = {-1, 0, 1, 1, 1, 0, -1, -1};
queue<pair<pair<int, int>, int> > q;

//posición del oro, y la posición inicial (siempre 0)
vector<pair<int, int> > v;
int size;

//estructuras para ejecutar el tsp
int DP[17][1<<17], limit; 

bool check_pos (int x, int y) {
	return ((x >= 0) && (x < n) && (y >= 0) && (y < m));
}

void bfs (int pos) {
	
	q.push(make_pair(make_pair(v[pos].first, v[pos].second), 0));
	memset(graph[pos], INF, sizeof graph[pos]);
	graph[pos][pos] = 0;
	visited[v[pos].first][v[pos].second] = true;
	
	pair<pair<int, int>, int>  act;
	int x, y, value, i, j, d, iv;
	
	while (!q.empty()) {
		
		act = q.front();
		q.pop();
		
		i = act.first.first;
		j = act.first.second;
		value = act.second + 1;
		
		for (d=0; d<8; d++) {
			
			x = i+dist1[d];
			y = j+dist2[d];
			
			if (check_pos(x, y) && !visited[x][y]) {
				
				visited[x][y] = true;
				
				q.push(make_pair(make_pair(x, y), value));
				
				if (matrix[x][y] == 'g') {
					for (iv=1; (v[iv].first != x) || (v[iv].second != y); iv++);
					graph[pos][iv] = value;
				} else if (matrix[x][y] == 'x') {
					graph[pos][0] = value;
				}
			}
		}
	}
}

int tsp (int pos, int bitmask) {
	
	if (bitmask == limit)
		return graph[pos][0];
	
	if (DP[pos][bitmask])
		return DP[pos][bitmask];
	
	int mn = MAX_INT;
	for (int i=1; i<size; i++) {
		if (pos != i) {
			if (bitmask & (1 << i))
				continue;
			mn = min(mn, tsp(i, bitmask | (1 << i)) + graph[pos][i]);
		}
	}
	
	return (DP[pos][bitmask] = mn);
}

int main() {
	
	int t, i, j;
	
	scanf("%d", &t);
	
	for (int it=1; it<=t; it++) {
		
		scanf("%d %d", &n, &m);
		
		v.push_back(make_pair(0, 0));
		for (i=0; i<n; i++) {
			scanf("%s", matrix[i]);
			for (j=0; j<m; j++) {
				if (matrix[i][j] == 'x')
					v[0].first = i, v[0].second = j;
				else if (matrix[i][j] == 'g')
					v.push_back(make_pair(i, j));
			}
		}
		
		size = v.size();
		for (i=0; i<size; i++)
			memset(visited, false, sizeof visited), bfs(i);
		
		limit = (1 << size) - 1;
		for (i=0; i<size; i++)
			memset(DP[i], 0, sizeof DP[i]);
		
		printf("Case %d: %d\n", it, tsp(0, 1));
		
		v.clear();
		
	}
	
	return 0;
} 
