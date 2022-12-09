/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1070
	Name: A Simple Calculation
	Number: 1070
	Date: 11/11/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <list>
#include <iterator>
#include <cstdlib>
#include <set>
#define sqr(x) (x*x)

using namespace std;

int cuadrados[101];
int rectangulos[101];
int sumatoria;

void inicializar() {
	cuadrados[0] = 0;
	cuadrados[1] = 1;
	rectangulos[0] = 0;
	rectangulos[1] = 1;
	sumatoria = 1;
	for (int i=2; i<101; i++) {
		sumatoria += i;
		cuadrados[i] = cuadrados[i-1] + sqr(i);
		rectangulos[i] = sqr(sumatoria);
	}
	
}

int main () {
	int n;
	
	inicializar();
	
	while (cin>>n) {
		printf("%d %d\n", cuadrados[n],rectangulos[n]);
	}
	
	return 0;
}
