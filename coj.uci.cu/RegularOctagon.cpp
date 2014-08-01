/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2853
	Name: Regular Octagon
	Number: 2853
	Date: 12/06/2014
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

double c;

double binary_search () {
	
	double lo = 0.0, hi = c, mid = (lo + hi) / 2.0;
		
	while (fabs(c-(2.41421356237*mid)) > EPS) {
		if ((c-(2.41421356237*mid)) > 0.0) lo = mid+EPS;
		else hi = mid-EPS;
		mid = (lo + hi) / 2.0;
	}
	
	return mid;
}

int main() {
	
	while (scanf("%lf", &c), c != 0.0)
		printf("%.3lf\n", 2.0*binary_search()*c);
	
	return 0;
} 
