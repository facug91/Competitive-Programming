/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2965
	Name: Square Formations
	Number: 2965
	Date: 11/07/2014
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

int n, k;
vector<int> squares;
bool is_square[1010050];

void init () {
	for (int i=1; i<=1005; i++)
		squares.push_back(i*i);
	memset(is_square, 0, sizeof is_square);
	for (int i=0; i<1005; i++)
		is_square[squares[i]] = true;
}

bool check (int n) {
	return ((n > k) && ((n-k) % 2 == 0) && is_square[((n-k)/2)+k]);
}

int main () {
	int t, i, j;
	
	scanf("%d", &t);
	
	init();
	
	for (int it=1; it<=t; it++) {
		
		scanf("%d", &k);
		for (i=0; !check(squares[i]); i++);
		
		printf("Case %d: %d\n", it, squares[i]-k);
	}
	
	
	return 0;
}
