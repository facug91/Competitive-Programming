/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2175
	Name: Prime Numbers Again
	Number: 2175
	Date: 28/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <iterator>

#define MAXN 100100

using namespace std;

bool criba[MAXN];
set<int> primos;

void init () {
	memset(criba, true, sizeof(criba));
	primos.insert(2);
	for (int i=3; i<320; i+=2) {
		if (criba[i]) {
			primos.insert(i);
			for (int j=i+i*2; j<MAXN; j+=i*2) {
				criba[j] = false;
			}
		}
	}
	for (int i=321; i<MAXN; i+=2) {
		if (criba[i]) {
			primos.insert(i);
		}
	}
}

int main () {
	int m, x, a, b;
	
	init();
	
	scanf("%d", &m);
	
	while (m--) {
		
		scanf("%d", &x);
		
		a = *(--(primos.upper_bound(x)));
		b = *(primos.lower_bound(x));
		
		printf("%d %d\n", a, b);
		
	}
	
	return 0;
}
