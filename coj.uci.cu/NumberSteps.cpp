/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1160
	Name: Number Steps
	Number: 1160
	Date: 18/11/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int n, x, y;

int main () {
	cin>>n;
	
	for(;n--;) {
		cin>>x>>y;
		
		if (x == y) {
			if (x % 2 == 0) {
				printf("%d\n",(x*2));
			} else {
				printf("%d\n",((x*2)-1));
			}
		} else if (x-2 == y) {
			if (y % 2 == 0) {
				printf("%d\n",((y*2)+2));
			} else {
				printf("%d\n",((y*2)+1));
			}
		} else {
			printf("No Number\n");
		}
	}
	
	return 0;
}
