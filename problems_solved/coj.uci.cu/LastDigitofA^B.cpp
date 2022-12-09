/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1388
	Name: Last Digit of A ^ B
	Number: 1388
	Date: 30/11/2013
*/

#include <iostream>
#include <cstdio>
#define square(x) ((x) * (x))

using namespace std;

int bigmod (int b, int p) {
	if (p == 0) {
		return 1;
	} else if (p % 2 == 0) {
		return square(bigmod(b, p/2)) % 10;
	} else {
		return ((b % 10) * bigmod(b, p-1)) % 10;
	}
}

int main() {
	int t, a, b;

	cin>>t;
	
	for (;t--;) {
		cin>>a>>b;
		printf("%d\n", bigmod(a, b));
	}
	
    return 0;
}
