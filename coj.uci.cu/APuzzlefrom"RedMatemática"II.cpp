/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2929
	Name: A Puzzle from "Red Matemática" II
	Number: 2929
	Date: 14/07/2014
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
#define MAXN 1000010

using namespace std;

int d, k;
int ans[10][9] = {{0, 0, 0, 0, 0, 0, 0, 0},
				  {0, 1, 4, 9, 16, 25, 36, 49, 64},
				  {0, 4, 16, 27, 37, 46, 54, 61, 67},
				  {0, 9, 18, 27, 36, 45, 54, 63, 72},
				  {0, 7, 19, 27, 40, 49, 54, 64, 70},
				  {0, 7, 10, 18, 31, 40, 45, 55, 70},
				  {0, 9, 18, 27, 36, 45, 54, 63, 72},
				  {0, 13, 25, 27, 37, 46, 54, 61, 76},
				  {0, 10, 22, 36, 52, 43, 54, 67, 73},
				  {0, 9, 18, 27, 36, 45, 54, 63, 72}};
	
int main () {
	int i, j;
	
	while (scanf("%d %d", &d, &k), d || k)
		printf("%d\n", (k/9)*81 + ans[d][k%9]);
	
	return 0;
}
