/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2460
	Name: Finding the Father
	Number: 2460
	Date: 26/06/2014
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
//
using namespace std;

int n, zero, aux;

int main () {
	
	while (scanf("%d", &n) != EOF) {
		aux = n | ((n & (-n)) - 1);
		zero = (~aux) & (aux+1);
		aux = (zero - 1) & (~(((n & (-n)) << 1) -1));
		if (aux) for (; !(aux&1); aux>>=1);
		n = ((n & (~(zero-1))) | zero) | aux;
		printf("%d\n", n);
	}
	
	return 0;
}
