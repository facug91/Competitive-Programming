/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1180
	Name: Bijele
	Number: 1180
	Date: 21/11/2013
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <iterator>

using namespace std;

int n, i, aux;
int piezas[] = {1, 1, 2, 2, 2, 8};

int main () {
	
	cin>>n;
	
	for (;n--;) {
		
		for(i=0;i<5; i++) {
			cin>> aux;
			printf("%d ",piezas[i]-aux);
		}
		cin>> aux;
		printf("%d\n",piezas[5]-aux);
		
	}
	
	return 0;
}
