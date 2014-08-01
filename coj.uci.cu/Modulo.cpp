/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1300
	Name: Modulo
	Number: 1300
	Date: 15/11/2013
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <set>
#include <iterator>

using namespace std;

set<int> numeros;
int n, i;

int main () {
	for (i=0; i<10; i++) {
		scanf("%d",&n);
		numeros.insert(n%42);
	}
	printf("%d\n",numeros.size());
	
	return 0;
}
