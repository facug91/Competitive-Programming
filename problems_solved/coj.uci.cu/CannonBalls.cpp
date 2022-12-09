/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1566
	Name: Cannon Balls
	Number: 1566
	Date: 18/11/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int respuestas[501];
int n, i;

void inicializar () {
	respuestas[0] = 0;
	for (i=1; i<=500; i++) {
		respuestas[i] = respuestas[i-1]+(i*i);
	}
}

int main () {
	
	inicializar();
	
	cin>>n;
	
	while (n) {
		printf("%d\n", respuestas[n]);
		cin>>n;
	} 
	
	return 0;
}
