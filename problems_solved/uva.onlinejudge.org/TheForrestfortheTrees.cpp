/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=540
	Name: The Forrest for the Trees
	Number: 599
	Date: 07/07/2014
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

using namespace std;

int tree, acorn;
vector<char> graph['Z'+1];
char s[100];
bool vis['Z'+1];
queue<char> q;

void bfs (char c) {
	q.push(c);
	char act;
	while (!q.empty()) {
		act = q.front();
		q.pop();
		int size = graph[act].size();
		for (int i=0; i<size; i++) {
			if (!vis[graph[act][i]]) {
				vis[graph[act][i]] = true;
				q.push(graph[act][i]);
			}
		}
	}
}

int main () {
	
	int t, i, j;
	
	scanf("%d", &t);
	
	while (t--) {
		
		while (scanf("%s", s), s[0]!='*') {
			graph[s[1]].push_back(s[3]);
			graph[s[3]].push_back(s[1]);
		}
		
		for (i='A'; i<='Z'; i++)
			vis[i] = false;
		scanf("%s", s); 
		tree = acorn = 0;
		
		if (!vis[s[0]]) {
			vis[s[0]] = true;
			if (graph[s[0]].size() == 0) acorn++;
			else {
				bfs(s[0]);
				tree++;
			}
		}
		for (i=2; s[i-1]; i+=2) {
			if (!vis[s[i]]) {
				vis[s[i]] = true;
				if (graph[s[i]].size() == 0) acorn++;
				else {
					bfs(s[i]);
					tree++;
				}
			}
		}
		
		printf("There are %d tree(s) and %d acorn(s).\n", tree, acorn);
		
		if (t) for (i='A'; i<='Z'; i++) graph[i].clear();
		
	}
	
	return 0;
}
