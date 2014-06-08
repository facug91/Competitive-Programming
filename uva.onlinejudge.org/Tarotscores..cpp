/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2166
	Name: Tarot scores.
	Number: 11225
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

int t, m, sum, oudlers, req[] = {56, 51, 41, 36};
char s[30];

void read_card () {
	
	gets(s);
	
	if ((strcmp(s, "fool") == 0) || (strcmp(s, "one of trumps") == 0) || (strcmp(s, "twenty-one of trumps") == 0)) {
		oudlers++;
		sum += 45;
	} else if (strncmp(s, "king", 4) == 0) {
		sum += 45;
	} else if (strncmp(s, "queen", 5) == 0) {
		sum += 35;
	} else if (strncmp(s, "knight", 6) == 0) {
		sum += 25;
	} else if (strncmp(s, "jack", 4) == 0) {
		sum += 15;
	} else {
		sum += 5;
	}
	
}

int main() {
	
	scanf("%d", &t);
	
	for (int it=1; it<=t; it++) {
		
		if (it != 1) printf("\n");
		
		scanf("%d", &m);
		getchar();
		
		sum = 0;
		oudlers = 0;
		
		for (int i=0; i<m; i++)
			read_card();
		
		sum /= 10;
		
		printf("Hand #%d\n", it);
		if (sum >= req[oudlers]) printf("Game won by %d point(s).\n", (sum-req[oudlers]));
		else printf("Game lost by %d point(s).\n", (req[oudlers]-sum));
		
	}
	
	return 0;
} 
