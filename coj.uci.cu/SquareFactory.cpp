/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2649
	Name: Square Factory
	Number: 2649
	Date: 11/12/2013
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <iterator>
#include <utility>
#include <set>
#define square(x) ((x) * (x))
#define tint long long int
#define mod 1000003

using namespace std;

int c;
tint n;

tint bigmod (tint a, tint p) {
	if (p == 0) {
		return 1;
	} else if (p % 2 == 0) {
		return (square(bigmod(a, p/2)) % mod);
	} else {
		return ((a * bigmod(a, p-1)) % mod);
	}
}

tint susecion (tint a, tint n) {
	if (n <= 3) {
		tint p=1, sum=1, i;
		for (i=1; i<=n; i++) {
			p *= a;
			sum += p;
		}
		return (sum % mod);
	} else if (n % 2 != 0) {
		return (((a+1) * susecion((a*a) % mod, n/2)) % mod);
	} else {
		return (((((a+1) * susecion((a*a) % mod, (n-1)/2)) % mod) + bigmod(a, n) % mod) % mod);
	}
}

int main() {
	cin>>c;
	
	for (;c--;) {
		cin>>n;
		printf("%d\n",susecion(4, n));
	}
	
    return 0;
}
