/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1326
	Name: Account Balance
	Number: 1326
	Date: 18/11/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int n, b, t, aux;
char c;

int main () {
	cin>>n;
	
	for (;n--;) {
		
		cin>>b>>t;
		
		for(;t--;) {
			cin>>c>>aux;
			(c=='C')?b+=aux:b-=aux;
		}
		
		printf("%d\n",b);
	}
	
	return 0;
}
