/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2629
	Name: Mondelo's Coins
	Number: 2629
	Date: 21/11/2013
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

const double PI = 3.141592653589793238462;
const double RAIZDE3 = 1.73205080756887729352;
int d;
double r, resultado;

int main () {
	
	while (cin>>d) {
		r = d / 2.0;
		r *= r;
		resultado = ((PI - RAIZDE3) * r) / 2.0;
		printf("%.3f\n",resultado);
	}
	
	return 0;
}
