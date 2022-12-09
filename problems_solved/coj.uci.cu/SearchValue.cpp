/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1423
	Name: Search Value
	Number: 1423
	Date: 06/12/2013
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <utility>
#include <cmath>

using namespace std;

double l;

int main() {
	while (cin>>l) {
		printf("%.6lf\n", ((l*sqrt(3))/4.0));
	}
	return 0;
}
