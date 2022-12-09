/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2628
	Name: Grid Successors
	Number: 11581
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
//const long double PI = 2*acos(0);

#define INF 1000000000
//
using namespace std;

int t;
bool g[2][3][3];
char s[5];

bool all_zeros (int idx) {
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			if (g[idx][i][j]) return false;
	return true;
}

int k () {
	int cont = -1, f = 0, s = 1;
	do {
		
		cont++;
		
		g[s][0][0] = g[f][0][1] ^ g[f][1][0];
		g[s][0][1] = g[f][0][0] ^ g[f][1][1] ^ g[f][0][2];
		g[s][0][2] = g[f][0][1] ^ g[f][1][2];
		g[s][1][0] = g[f][0][0] ^ g[f][1][1] ^ g[f][2][0];
		g[s][1][1] = g[f][0][1] ^ g[f][1][0] ^ g[f][1][2] ^ g[f][2][1];
		g[s][1][2] = g[f][1][1] ^ g[f][0][2] ^ g[f][2][2];
		g[s][2][0] = g[f][2][1] ^ g[f][1][0];
		g[s][2][1] = g[f][2][0] ^ g[f][2][2] ^ g[f][1][1];
		g[s][2][2] = g[f][2][1] ^ g[f][1][2];
		
		f ^= s ^= f ^= s; //swap();
		
	} while (!all_zeros(f));
	
	return cont;
}

int main() {
	
	int i, j;
	
	scanf("%d", &t);
	
	while (t--) {
		for (i=0; i<3; i++) {
			scanf("%s", s);
			g[0][i][0] = s[0]-'0';
			g[0][i][1] = s[1]-'0';
			g[0][i][2] = s[2]-'0';
		}
		
		if (all_zeros(0)) printf("-1\n");
		else printf("%d\n", k());
		
	}
	
	return 0;
} 
