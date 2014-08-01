/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2651
	Name: Rice and Beans
	Number: 2651
	Date: 03/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>
#define square(x) ((x) * (x))

using namespace std;

const double RAIZDETRES = 1.7320508075688772935274463415059;
const double PI = 3.141592654;
int t, i;
double L, rice, beans, r, triangulo;

int main() {
	cin>>t;
	
	for (i=1; i<=t; i++) {
		cin>>L;
		
		r = L / PI / 2.0;
		triangulo = square(r) * RAIZDETRES / 4.0;
		rice = triangulo * 2.5;
		beans = triangulo * 3.5;
		
		printf("Case %d\n", i);
		printf("Rice: %.2f\n", rice);
		printf("Beans: %.2f\n", beans);
	}
	
    return 0;
}
