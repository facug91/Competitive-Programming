/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1157
	Name: u Calculate e
	Number: 1157
	Date: 22/11/2013
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

int i, j, r;
double valores[10];
double factoriales[10];

int main () {
	
	factoriales[0] = 1.0;
	for(i=1; i<10; i++) {
		factoriales[i] = factoriales[i-1]*i;
	}
	
	valores[0] = 1.0;
	for(i=1; i<10; i++) {
		valores[i] = valores[i-1] + (1/factoriales[i]);
	}
	
	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");
	for (i=3; i<10; i++) {
		printf("%d %.9f\n", i, valores[i]);
	}
	
	return 0;
}
