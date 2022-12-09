/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=
	Name: PARKET
	Number: 2656
	Date: 12/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <vector>

#define tint unsigned long long int
#define MAX_INT 2147483647

using namespace std;



int main () {
	int r, b, i;
	
	cin>>r>>b;
	
	
	i = 0;
	do {
		do {
			i++;
		} while (b % i != 0);
	} while ((i+1)*2+(b/i+1)*2 != r);
	
	printf("%d %d\n", b/i+2, i+2);
	
	return 0;
}
