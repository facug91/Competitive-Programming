/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1790
	Name: Move the bishop
	Number: 10849
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
//#include <cmath>
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

int c, t, n, x1, y1, x2, y2;

bool check_pos(int x, int y) {
	return ((x >= 1) && (x <= n) && (y >= 1) && (y <= n));
}

int main() {
	
	scanf("%d", &c);
	
	while (c--) {
		
		scanf("%d", &t);
		scanf("%d", &n);
		
		while (t--) {
			
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			
			if (!check_pos(x1, y1) || !check_pos(x2, y2)) printf("no move\n");
			else if ((x1 == x2) && (y1 == y2)) printf("0\n");
			else if (abs(x1-x2) == abs(y1-y2)) printf("1\n");
			else if (((x1+y1)%2) == ((x2+y2)%2)) printf("2\n");
			else printf("no move\n");
			
		}
		
	}
	
	return 0;
} 
