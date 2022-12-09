/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1004
	Name: Traversing Grid
	Number: 1004
	Date: 12/11/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int t, n, m;

int main () {
	
	cin>>t;
	
	for (;t--;) {
	
		cin>>n>>m;
		
		if (n == m) {
			if (n % 2 == 0) {
				printf("L\n");
			} else {
				printf("R\n");
			}
		} else {
			if (n > m) {
				if (m % 2 == 0) {
					printf("U\n");
				} else {
					printf("D\n");
				}
			} else {
				if (n % 2 == 0) {
					printf("L\n");
				} else {
					printf("R\n");
				}
			}
		}
	}
	
	return 0;
}
