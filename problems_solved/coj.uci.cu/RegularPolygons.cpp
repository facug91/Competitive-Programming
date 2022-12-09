/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1066
	Name: Regular Polygons
	Number: 1066
	Date: 06/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

const double PI = 3.141592653589793;

int t;
double r, n, res1, res2;

int main () {
	scanf("%d", &t);
	
	while(t--) {
		scanf("%lf %lf", &r, &n);
		res1 = (sin((PI)/n) * r) * 2.0 * n;
		res2 = (tan(PI/n) * r) * 2.0 * n;
		printf("%.4lf %.4lf\n", res1, res2);
	}
	
	return 0;
}
