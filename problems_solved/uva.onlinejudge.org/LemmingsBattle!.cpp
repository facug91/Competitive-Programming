/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=919
	Name: Lemmings Battle!
	Number: 978
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

int bf, sg, sb, s, green[2][101], g, blue[2][101], b;


int main () {
	
	int t, i, j;
	
	scanf("%d", &t);
	
	while (t--) {
		
		for (i=0; i<2; i++)
			for (j=0; j<101; j++)
				green[i][j]=0, blue[i][j]=0;
		
		scanf("%d %d %d", &bf, &sg, &sb);
		
		for (i=0; i<sg; i++) {
			scanf("%d", &s);
			green[0][s]++;
		}
		
		for (i=0; i<sb; i++) {
			scanf("%d", &s);
			blue[0][s]++;
		}
		
		g = b = 0;
		while (sg && sb) {
			int until = min(bf, min(sg, sb)), nextg = 100, nextb = 100;
			for (i=0; i<until; i++) {
				while (green[g][nextg] == 0) nextg--;
				while (blue[b][nextb] == 0) nextb--;
				if (nextg == nextb) {
					sg--; 
					sb--;
				} else if (nextg > nextb) {
					sb--;
					green[(g+1)%2][nextg-nextb]++;
				} else {
					sg--;
					blue[(b+1)%2][nextb-nextg]++;
				}
				green[g][nextg]--;
				blue[b][nextb]--;
			}
			for (i=1; i<101; i++) {
				blue[(b+1)%2][i] += blue[b][i];
				blue[b][i] = 0;
				green[(g+1)%2][i] += green[g][i];
				green[g][i] = 0;
			}
			b = (b+1)%2;
			g = (g+1)%2;
		}
		
		if (!sg && !sb) printf("green and blue died\n");
		else if (!sg) {
			printf("blue wins\n");
			for (i=100; i>0; i--)
				for (j=0; j<blue[b][i]; j++)
					printf("%d\n", i);
		} else {
			printf("green wins\n");
			for (i=100; i>0; i--)
				for (j=0; j<green[g][i]; j++)
					printf("%d\n", i);
		}
		
		if (t) printf("\n");
	}
	
	return 0;
}
