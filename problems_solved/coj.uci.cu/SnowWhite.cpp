/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1324
	Name: Snow White
	Number: 1324
	Date: 12/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <queue>

#define tint unsigned long long int
#define MAX_INT 2147483647
#define MAX_DBL 1e+37

using namespace std;

struct cmp {
	bool operator() (int a, int b) {
		return a > b;
	}
};

int numero[9];
priority_queue<int, vector<int>, cmp> cola;

int main () {

	int i, j, k, sum = 0;
	bool listo = false;
	
	for (i=0; i<9; i++) {
		scanf("%d", &numero[i]);
		sum += numero[i];
	}
	
	i = -1;
	while (!listo) {
		i++;
		sum -= numero[i];
		j = i+1;
		while ((!listo) && (j<9)) {
			sum -= numero[j];
			if (sum == 100) {
				listo = true;
			} else {
				sum += numero[j];
				j++;
			}
		}
		if (!listo) {
			sum += numero[i];
		}
	}
	
	for (k=0; k<9; k++) {
		if ((k != i) && (k != j)) {
			cola.push(numero[k]);
		}
	}
	
	for (i=0; i<7; i++) {
		printf("%d\n", cola.top());
		cola.pop();
	}
	
	return 0;
}
