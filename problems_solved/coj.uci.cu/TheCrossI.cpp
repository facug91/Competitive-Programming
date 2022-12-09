/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=5
	Name: The Cross I
	Number: 1355
	Date: 09/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#define tint unsigned long long int

using namespace std;

int main () {
	
	double a, r;
	
	while (scanf("%lf", &a) != EOF) {
		r = ((2.0 / 3.0) - (3.141592653589793/9.0)) * a * a;
		printf("%.4lf\n", r);
	}
	
	return 0;
}
