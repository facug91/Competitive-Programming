/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2625
	Name: Gift Problem
	Number: 2625
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <vector>

#define tint unsigned long long int
#define MAX_INT 2147483647
#define MAX_DBL 1e+37

using namespace std;

char letras[] = {'O', 'I', 'E'};

int main () {
	int f, c, i, j, l, laux;
	
	scanf("%d %d", &f, &c);
	l = 0;
	for (i=0; i<f; i++) {
		laux = l;
		for (j=0; j<c; j++) {
			printf("%c", letras[laux]);
			laux = (laux + 1) % 3;
		}
		printf("\n");
		l = (l + 1) % 3;
	}
	
	return 0;
}
