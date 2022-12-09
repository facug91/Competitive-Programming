/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1168
	Name: Forests
	Number: 10227
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

int p, t, a, b;
set<int> people[101];
set<set<int> > opinions;
char s[10], *pc = new char[5];
bool first = true;

int main() {
	int n, i, j, k;
	
	scanf("%d", &n);
	
	while (n--) {
		
		if (first) first = false;
		else printf("\n");
		
		scanf("%d %d", &p, &t);
		getchar();
		
		if (p == 0) {
			printf("0\n");
		} else {
			for (i=1; i<=p; i++)
				people[i].clear();
			opinions.clear();
			
			bool pass = false;
			while ((gets(s) != NULL) && (s[0])) {
				pass = true;
				pc = strtok(s, " ");
				a = atoi(pc);
				pc = strtok(NULL, " ");
				b = atoi(pc);
				people[a].insert(b);
			}
			
			if (!pass) printf("1\n");
			else {
				for (i=1; i<=p; i++)
					opinions.insert(people[i]);
				
				printf("%d\n", opinions.size());
			}
			
		}
		
	}
	
	return 0;
} 
