/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2633
	Name: Max Volume
	Number: 2633
	Date: 12/12/2013
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

const double PI = 3.14159;

int main () {
	
	int n;
	double max = 0.0, r, h, aux;
	char c;
	
	cin>>n;
	while (n--) {
		cin>>c;
		if (c == 'C') {
			cin>>r>>h;
			aux = (1.0/3.0)*PI*r*r*h;
		} else if (c == 'L') {
			cin>>r>>h;
			aux = PI*r*r*h;
		} else {
			cin>>r;
			aux = (4.0/3.0)*PI*r*r*r;
		}
		if (max < aux) max = aux;
	}
	
	printf("%.3lf\n", max);
	
	return 0;
}
