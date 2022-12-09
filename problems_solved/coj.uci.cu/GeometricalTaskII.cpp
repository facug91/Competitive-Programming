/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1493
	Name: Geometrical Task II
	Number: 1493
	Date: 23/11/2013
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#define sqr(x) (x*x)

using namespace std;

const double PI = 3.14;

string s;
double r, a, b, resultado;

int main () {
	
	cin>>s;
	
	if (s == "circle") {
		cin>>r;
		resultado = (PI * r * r);
	} else {
		cin>>a>>b;
		resultado = ((a * b) / 2.0);
	}
	
	printf("%.2f\n",resultado);
	
	return 0;
}
