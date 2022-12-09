/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3399
	Name: Jollo
	Number: 12247
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

int a, b, c, x, y, z;
int v[5];

inline void assign (int mn) {
	
	v[0] = a; v[1] = b; v[2] = c; v[3] = x; v[4] = y;
	sort(v, v+5);
	
	for (int i=0; i<5; i++) {
		
		if (mn < v[i]) {
			z = mn;
			return;
		}
		
		if (mn == v[i]) mn++;
		
	}
	
	if (mn <= 52) z = mn;
	else z = -1;
}

int main() {
	
	while (scanf("%d %d %d %d %d", &a, &b, &c, &x, &y), a) {
		
		if (a < b) a ^= b ^= a ^= b;
		if (b < c) c ^= b ^= c ^= b;
		if (a < b) a ^= b ^= a ^= b;
		
		if (x < y) x ^= y ^= x ^= y;
		
		if (y > a) assign(1);
		else if (y > b) assign(b+1);
		else if (x > a) assign(a+1);
		else z = -1;;
		
		printf("%d\n", z);
		
	}
	
	return 0;
} 
