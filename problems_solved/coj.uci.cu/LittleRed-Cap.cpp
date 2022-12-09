/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2553
	Name: Little Red-Cap
	Number: 2553
	Date: 07/05/2013
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

#define tint unsigned long long int
#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9;

using namespace std;

long long DP[30005];
long long alternativas[30005];
vector<int> grafo[30005];
int n, s;

inline void dp () {
	int i, j;
	DP[n] = alternativas[n] = 1;
	
	long long c, a; int ig;
	for (i=n-1; i>=1; i--) {
		c = -1; a = 0;
		for ( j=0; j<grafo[i].size(); j++) {
			c = max(c, DP[ig=grafo[i][j]]);
			a += alternativas[ig];
		}
		DP[i] = c + (alternativas[i]=a);
	}
}

int main() {
	
	int a, b, i;
	//Índice desde 1 ***
	
	scanf("%d %d", &n, &s);
	
	for (i=0; i<s; i++) {
		scanf("%d %d", &a, &b);
		grafo[a].push_back(b);
	}
	
	dp();
	
	printf("%lld\n", DP[1]);
	
	return 0;
}
