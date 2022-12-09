/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2658
	Name: Arithmetic Progression
	Number: 2658
	Date: 02/12/2013
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <iterator>
#include <utility>
#include <set>
#define tint unsigned long long int

using namespace std;

int t;
tint f, l, s, i, end, divi, sum, cant;
set<tint> divisores;
set<tint>::iterator itr;

void calcularDivisores(tint n) {
	divisores.clear();
	divisores.insert(1);
	divisores.insert(n);
	end = n / 2;
	for (i=2; i<end; i++) {
		if (n % i == 0) {
			divisores.insert(i);
			end = n / i;
			divisores.insert(end);
		}
	}
}

int main() {
	cin>>t;
	
	for (;t--;) {
		cin>>f>>l>>s;
		
		if (f != l) {
			calcularDivisores(l-f);
			
			divi = 0;
			for (itr=divisores.begin(); (itr != divisores.end()) && (divi == 0); itr++) {
				sum = 0;
				cant = 0;
				for (i=f-(*itr)-(*itr); i<=l+(*itr)+(*itr); i+=(*itr)) {
					cant++;
					sum += i;
				}
				if (sum == s) {
					divi = (*itr);
				}
			}
			printf("%llu\n", cant);
			printf("%llu", f-divi-divi);
			for (i=f-divi; i<=l+divi+divi; i+=divi) {
				printf(" %llu",i);
			}
			printf("\n");
		} else {
			cant = s / f;
			printf("%llu\n", cant);
			printf("%llu", f);
			for (i=1; i<cant; i++) {
				printf(" %llu",f);
			}
			printf("\n");
		}
	}
	
    return 0;
}
