/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1166
	Name: Speed
	Number: 1166
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <list>
#include <iterator>
#include <cstdlib>
#include <set>

using namespace std;

int main () {
	int t, n, par, impar, aux;
	cin>>t;
	for(;t--;) {
		cin>>n;
		par = impar = 0;
		for(;n--;) {
			cin>>aux;
			if (aux % 2 == 0) {
				par++;
			} else {
				impar++;
			}
		}
		printf("%d even and %d odd.\n",par,impar);
	}
	
	
	return 0;
}
