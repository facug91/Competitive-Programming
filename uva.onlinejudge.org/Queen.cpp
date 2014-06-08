/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2489
	Name: Queen
	Number: 11494
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

int x1, y1, x2, y2;

int main() {
	
	while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2), x1) {
		
		if ((x1 == x2) && (y1 == y2)) printf("0\n");
		else if ((x1 == x2) || (y1 == y2) || (abs(x1-x2) == abs(y1-y2))) printf("1\n");
		else printf("2\n");
		
	}
	
	return 0;
} 
