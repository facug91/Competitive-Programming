/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2205
	Name: Counting Ones
	Number: 2205
	Date: 14/11/2013
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

unsigned long long int cantidadDeUnos(unsigned long long int n) {
	unsigned long long int i, aux, total = 0;
	
	for (i=2; i<=n; i*=2) {
		if (n % i != 0) { 
			aux = n + (i - (n % i));
			total += ((aux/2) - ((i - (n % i)) - 1));
			if (n < (aux - (i/2))) {
				total += (((aux - (i/2)) - n) - 1);
			}
		} else {
			total += (n/2);
		}
	}
	
	total += ((n - (i/2)) + 1);
	
	return total;
}

unsigned long long int a, b, r, i, cantA, cantB, t;

int main() {
	
	cin>>t;
	
	for(;t--;) {
	cin>>a>>b;
	
	if (b == 0) {
		printf("0\n");
	} else {
		if (a == 0) {
			cantB = cantidadDeUnos(b);
			printf("%llu\n",cantB);
		} else {
			r = 0;
			
			for(i=a; i!=0; i/=2) {
				r += (i % 2);
			}
			
			cantA = cantidadDeUnos(a);
			cantB = cantidadDeUnos(b);
			
			
			
			r += (cantB - cantA);
			
			printf("%llu\n",r);
		}
	}
	}
	return 0;
}
