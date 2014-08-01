/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2762
	Name: Cow Art
	Number: 2762
	Date: 29/06/2014
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

int n, p[2], dist1[] = {0, 1, 0, -1}, dist2[] = {1, 0, -1, 0};
char paint[2][105][105]; //0 = human ; 1 = cow
bool visited[105][105];
queue<pair<int, int> > q;

bool check_pos (int x, int y) {
	return ((x >= 0) && (x < n) && (y >= 0) && (y < n));
}

void cancel (int p, int i, int j) {
	q.push(make_pair(i, j));
	pair<int, int> act;
	int x, y, w, z;
	while (!q.empty()) {
		act = q.front();
		q.pop();
		x = act.first; y = act.second;
		for (int d=0; d<4; d++) {
			w = x+dist1[d]; z = y+dist2[d];
			if ((check_pos(w, z)) && (paint[p][x][y] == paint[p][w][z]) && (!visited[w][z]))
				q.push(make_pair(w, z)), visited[w][z] = true;
		}
	}
}

int main () {
	
	int i, j, k;
	
	scanf("%d", &n);
	
	for (i=0; i<n; i++) {
		scanf("%s", paint[0][i]);
		strcpy(paint[1][i], paint[0][i]);
	}
	
	for (i=0; i<n; i++)
		for (j=0; j<n; j++)
			if (paint[1][i][j] == 'G')
				paint[1][i][j] = 'R';
	
	p[0] = p[1] = 0;
	for (k=0; k<2; k++) {
		for (i=0; i<n; i++)
			memset(visited[i], 0, sizeof visited[i]);
		for (i=0; i<n; i++)
			for (j=0; j<n; j++)
				if (!visited[i][j])
					cancel(k, i, j), p[k]++;
	}
	
	printf("%d %d\n", p[0], p[1]);
	
	return 0;
}
