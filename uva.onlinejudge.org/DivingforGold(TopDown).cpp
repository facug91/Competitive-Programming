/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=931
	Name: Diving for Gold
	Number: 990
	Date: 02/07/2014
	Using: Top-Down approach
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

int t, w, n, deaph[35], gold[35];
pair<int, int> DP[35][1005];

pair<int, int> dp (int id, int t) {
	
	if ((id == n) || (t == 0)) return make_pair(0, 0);
	
	if (DP[id][t].first != -1) return DP[id][t];
	
	if (deaph[id] > t) return (DP[id][t] = dp(id+1, t));
	
	pair<int, int> aux0 = dp(id+1, t-deaph[id]);
	aux0.first += gold[id]; aux0.second |= (1<<id);
	
	pair<int, int> aux1 = dp(id+1, t);
	
	if (aux0.first > aux1.first) return (DP[id][t] = aux0);
	
	return (DP[id][t] = aux1);
	
}

int main() {
	
	int i, j, k;
	bool first = true;
	
	while (scanf("%d %d", &t, &w) != EOF) {
		
		if (first) first = false;
		else printf("\n");
		
		scanf("%d", &n);
		
		for(i=0; i<n; i++) {
			scanf("%d %d", deaph+i, gold+i);
			deaph[i] *= w*3;
		}
		
		for (i=0; i<=n; i++)
			for (j=0; j<=t; j++)
				DP[i][j].first = -1;
		
		pair<int, int> ans = dp(0, t);
		
		int cont = 0, bitmask = ans.second;
		printf("%d\n", ans.first);
		for (i=0; i<32; i++)
			if (bitmask & (1<<i))
				cont++;
		printf("%d\n", cont);
		for (i=0; i<32; i++)
			if (bitmask & (1<<i))
				printf("%d %d\n", deaph[i]/w/3, gold[i]);
		
	}
	
	return 0;
}
