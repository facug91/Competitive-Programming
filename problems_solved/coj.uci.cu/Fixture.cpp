/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2057
	Name: Fixture
	Number: 2057
	Date: 05/06/2014
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

int n, p[10], s[10];
char partida[10][105];

int main() {
	
	int i, j;
	
	while (scanf("%d", &n), n != -1) {
		
		for (i=2; i<=n; i++) {
			scanf("%s", partida[i]);
			s[i] = strlen(partida[i]);
		}
		memset(p, 0, sizeof p);
		
		bool solved = false;
		
		while (!solved) {
			solved = true;
			for (i=2; i<=n; i++) {
				if (p[i] != s[i]) {
					solved = false;
					j = partida[i][p[i]]-'0';
					if ((i+'0') == partida[j][p[j]]) {
						p[i]++; p[j]++;
					} else if (partida[i][p[i]] == '1') {
						partida[1][p[1]++] = i+'0';
						p[i]++;
					}
				}
			}
		}
		
		partida[1][p[1]] = 0;
		
		printf("%s\n", partida[1]);
		
	}
	
	return 0;
} 
