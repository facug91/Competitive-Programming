/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2422
	Name: Betty and the Modular Exponentiation
	Number: 2422
	Date: 30/11/2013
*/

#include <iostream>
#include <cstdio>
#define square(x) ((x) * (x))
#define tint unsigned long long int

using namespace std;

tint bigmod (tint b, tint p) {
	if (p == 0) {
		return 1;
	} else if (p % 2 == 0) {
		return square(bigmod(b, p/2)) % 1000000000;
	} else {
		return ((b % 1000000000) * bigmod(b, p-1)) % 1000000000;
	}
}

int main() {
	tint t, a, b;
	
	cin>>t;
	
	for (;t--;) {
		cin>>a>>b;
		printf("%d\n", bigmod(a, b));
	}
	
    return 0;
}
