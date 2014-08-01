/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2870
	Name: Pearls
	Number: 2870
	Date: 16/07/2014
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

int c, a[110], p[110];
map<pair<int, int>, int> DP;

int dp (int idx, int cant) {
	map<pair<int, int>, int>::iterator itr = DP.find(make_pair(idx, a[idx]+cant));
	if (itr != DP.end()) return (*itr).second;
	
	if (idx == c-1) {
		DP.insert(make_pair(make_pair(idx, a[idx]+cant), (a[idx]+cant+10)*p[idx]));
		return (a[idx]+cant+10)*p[idx];
	}
	
	int aux = min(dp(idx+1, cant+a[idx]), dp(idx+1, 0)+((a[idx]+cant+10)*p[idx]));
	
	DP.insert(make_pair(make_pair(idx, a[idx]+cant), aux));
	
	return aux;
}

int main () {
	int t, i, j;
	
	scanf("%d", &t);
	
	while (t--) {
		
		DP.clear();
		
		scanf("%d", &c);
		
		for (i=0; i<c; i++)
			scanf("%d %d", a+i, p+i);
		
		printf("%d\n", dp(0, 0));
		
	}
	
	return 0;
}
