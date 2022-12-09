/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1078
	Name: Another Candies
	Number: 1078
	Date: 15/11/2013 
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int t, total, aux, n, i;

int main () {
	
	cin>>t;
	
	for(;t--;) {
		cin>>n;
		i = n;
		
		total = 0;
		for(;i--;) {
			cin>>aux;
			total += aux;
		}

		(total%n) ? printf("NO\n") : printf("YES\n");
	}
	return 0;
}
