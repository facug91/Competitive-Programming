/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2608
	Name: Counting Ones II
	Number: 2608
	Date: 14/11/2013
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

unsigned long long int a, b, r, i, aux, totalA, totalB;

int main() {
	
	cin>>a>>b;
	
	r = 0;	
	for(i=a; i!=0; i/=2) {
		r += (i % 2);
	}
	
	
	totalA = 0;
	
	for (i=2; i<=a; i*=2) {
		if (a % i != 0) { 
			aux = a + (i - (a % i));
			totalA += ((aux/2) - ((i - (a % i)) - 1));
			if (a < (aux - (i/2))) {
				totalA += (((aux - (i/2)) - a) - 1);
			}
		} else {
			totalA += (a/2);
		}
	}
	
	totalA += ((a - (i/2)) + 1);
	
	
	totalB = 0;
	
	for (i=2; i<=b; i*=2) {
		if (b % i != 0) { 
			aux = b + (i - (b % i));
			totalB += ((aux/2) - ((i - (b % i)) - 1));
			if (b < (aux - (i/2))) {
				totalB += (((aux - (i/2)) - b) - 1);
			}
		} else {
			totalB += (b/2);
		}
	}
	
	totalB += ((b - (i/2)) + 1);
	
	r += (totalB - totalA);
	
	printf("%llu\n",r);
	
	return 0;
}
