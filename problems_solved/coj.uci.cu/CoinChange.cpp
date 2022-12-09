/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1103
	Name: Coin Change
	Number: 1103
	Date: 06/12/2013
*/

#include <cstdio>
#include <iostream>
#include <utility>
#define tint unsigned long long int

using namespace std;

tint valores[10000];
tint monedas[] = {1, 5, 10, 25, 50};
int n;

void init () {
	int i, j, c;
	valores[0] = 1;
	for (i=0; i<5; i++) {
		c = monedas[i];
		for (j=c; j<= 10000; j++) {
			valores[j] += valores[j-c];
		}
	}
}

int main () {
	init();
	
	while (cin>>n) {
		printf("%llu\n",valores[n]);
	}
	
	return 0;
}
