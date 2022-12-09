/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2052
	Name: Awari 2.0
	Number: 2052
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

int n, box[505];

int main() {
	
	int i, j;
	
	while (scanf("%d",&n), n != -1) {
		
		for (i=1; i<=n; i++)
			scanf("%d", &box[i]);
		
		bool solved = false, no_move;
		
		while (!solved) {
			solved = true;
			no_move = true;
			for (i=1; i<=n; i++) {
				if (box[i]) solved = false;
				if (box[i] == i) {
					no_move = false;
					box[i] = 0;
					for (j=i-1; j>0; j--) 
						box[j]++;
					break;
				}
			}
			if (no_move) break;
		}
		
		if (solved) printf("S\n");
		else printf("N\n");
		
	}
	
	
	
	return 0;
} 
