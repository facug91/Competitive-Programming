/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1448
	Name: Waking up brain
	Number: 10507
	Date: 18/07/2014
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

using namespace std;

int n, m, ans, con;
vector<char> graph['Z'+1];
bool awake['Z'+1], just['Z'+1], changed;
char s[5];

int main() {
	int i, j, k;
	
	while (scanf("%d %d", &n, &m) != EOF) {
		
		for (i='A'; i<='Z'; i++)
			graph[i].clear();
		memset(awake, 0, sizeof awake);
		
		scanf("%s", s);
		awake[s[0]] = true;
		awake[s[1]] = true;
		awake[s[2]] = true;
		
		for (i=0; i<m; i++) {
			scanf("%s", s);
			graph[s[0]].push_back(s[1]);
			graph[s[1]].push_back(s[0]);
		}
		
		ans = 3;
		
		for (k=0, changed=true; (ans!=n) && (changed); k++) {
			for (i='A'; i<='Z'; i++)
				just[i] = false;
			changed = false;
			for (i='A'; i<='Z'; i++) {
				if (!awake[i]) {
					con = 0;
					for (j=0; j<graph[i].size(); j++)
						if (awake[graph[i][j]])
							con++;
					if (con > 2) {
						changed = true;
						ans++;
						just[i] = true;
					}
				}
			}
			for (i='A'; i<='Z'; i++)
				awake[i] |= just[i];
		}
		
		if (ans == n) printf("WAKE UP IN, %d, YEARS\n", k);
		else printf("THIS BRAIN NEVER WAKES UP\n");
		
	}
	
	return 0;
} 
