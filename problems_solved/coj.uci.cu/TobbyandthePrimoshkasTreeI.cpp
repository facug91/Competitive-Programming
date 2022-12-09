/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2932
	Name: Tobby and the Primoshkas’ Tree I
	Number: 2932
	Date: 13/07/2014
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
#define MAXN 1000010

using namespace std;

int n, q, u, v, op, f;
bool primoshkas[101];
vector<int> tree[101];

void create () {
	queue<int> q;
	int act, i;
	q.push(f);
	
	while (!q.empty()) {
		act = q.front();
		q.pop();
		if (primoshkas[act]) primoshkas[act] = false;
		else primoshkas[act] = true;
		for (i=0; i<tree[act].size(); i++)
			q.push(tree[act][i]);
	}
}

int collect () {
	queue<int> q;
	int act, ans = 0, i;
	q.push(f);
	
	while (!q.empty()) {
		act = q.front();
		q.pop();
		ans += primoshkas[act];
		for (i=0; i<tree[act].size(); i++)
			q.push(tree[act][i]);
	}
	
	return ans;
}

int main () {
	int i, j;
	
	while (scanf("%d %d", &n, &q) != EOF) {
		
		for (i=0; i<n; i++) {
			primoshkas[i] = 0;
			tree[i].clear();
		}
		
		for (i=0; i<n-1; i++) {
			scanf("%d %d", &u, &v);
			tree[u].push_back(v);
		}
		
		for (i=0; i<q; i++) {
			scanf("%d %d", &op, &f);
			if (op == 0) create();
			else printf("%d\n", collect());
		}
		
	}
	
	return 0;
}
