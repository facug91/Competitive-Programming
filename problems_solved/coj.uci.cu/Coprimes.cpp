/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1050
	Name: Coprimes
	Number: 1050
	Date: 04/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int n, cont = 1, i = 2;

int gcd (int a, int b) {
	int c;
	while (b != 0) {
		c = b;
		b = a % b;
		a = c;
	}
	return a;
}

int main() {
	cin>>n;
	
	for (; i<n; i++) {
		if (gcd(n, i) == 1) {
			cont++;
		}
	}
	printf("%d\n", cont);
	
    return 0;
}
