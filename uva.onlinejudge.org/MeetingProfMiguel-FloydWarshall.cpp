/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1112
	Name: Meeting Prof. Miguel...
	Number: 10171
	Date: 27/06/2014
	Using -> Floyd-Warshall's Algorithm
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

int n, graph[2][30][30], ans, aux;
char pos[2];
vector<char> v_ans;

void floyd_warshall (int p) {
	int i, j, k;
	for (k=0; k<30; k++)
		for (i=0; i<30; i++)
			for (j=0; j<30; j++)
				graph[p][i][j] = min(graph[p][i][j], graph[p][i][k] + graph[p][k][j]);
}

int main () {
	
	int i, j, w, p;
	char a, d, u, v;
	
	while (scanf(" %d", &n), n) {
		
		for (i=0; i<30; i++) {
			for (j=0; j<30; j++){
				graph[0][i][j] = INF;
				graph[1][i][j] = INF;
			}
			graph[0][i][i] = 0; 
			graph[1][i][i] = 0;
		}
		
		for (i=0; i<n; i++) {
			scanf(" %c %c %c %c %d", &a, &d, &u, &v, &w);
			p = (a == 'M') ? 1 : 0;
			u -= 'A';
			v -= 'A';
			if (graph[p][u][v] > w)
				graph[p][u][v] = w;
			if ((d == 'B') && (graph[p][v][u] > w)) graph[p][v][u] = w;
		}
		scanf(" %c %c", &pos[0], &pos[1]);
		pos[0] -= 'A';
		pos[1] -= 'A';
		
		floyd_warshall(0);
		floyd_warshall(1);
		
		ans = INF;
		for (i=0; i<30; i++) {
			aux = graph[0][pos[0]][i]+ graph[1][pos[1]][i];
			if (aux < ans) {
				ans = aux;
				v_ans.clear();
				v_ans.push_back((char)(i+'A'));
			} else if (aux == ans)
				v_ans.push_back((char)(i+'A'));
		}
			
		if (ans == INF) printf("You will never meet.\n");
		else {
			printf("%d", ans);
			for (i=0; i<v_ans.size(); i++)
				printf(" %c", v_ans[i]);
			printf("\n");
		}
		
	}
	
	return 0;
}
