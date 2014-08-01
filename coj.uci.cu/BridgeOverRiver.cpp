/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2854
	Name: Bridge Over River
	Number: 2854
	Date: 27/06/2014
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

double l, xa, ya, xb, yb;

double point_distance (double x0, double y0, double x1, double y1) {
	return pow((((x0-x1)*(x0-x1))+((y0-y1)*(y0-y1))), 0.5);
}

double f(double x) {
	return (point_distance(xa, ya, x, l/2.0)+point_distance(xb, yb, x, -l/2.0));
}

double ternary_search () {
	
	double lo = 0.0, hi = 2000.0, mid1, mid2, ter;
	
	while (fabs(hi-lo) > EPS) {
		ter = (hi-lo)/3.0;
		mid1 = lo+ter;
		mid2 = lo+ter*2.0;
		if (f(mid1) > f(mid2)) lo = mid1;
		else hi = mid2;
	}
	
	return f(lo);
}

int main () {
	
	int t;
	
	scanf("%d", &t);
	
	while (t--) {
		
		scanf("%lf %lf %lf %lf %lf", &l, &xa, &ya, &xb, &yb);
		
		if (xa < 0.0) {
			xb -= xa;
			xa = 0.0;
		}
		if (xb < 0.0) {
			xa-= xb;
			xb = 0.0;
		}
		
		printf("%.3lf\n", ternary_search()+l);
		
	}
	
	return 0;
}
