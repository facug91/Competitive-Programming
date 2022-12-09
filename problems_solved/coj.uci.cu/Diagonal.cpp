/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1937
	Name: Diagonal
	Number: 1937
	Date: 30/11/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#define tint unsigned long long int

using namespace std;

tint n;
int i;

int main () {
	cin>>n;
	i=1;
	while(n) {
		printf("Case %d: %d\n", i, (int) ceil(1.5 + sqrt(2.25 + 2 * n)));
		i++;
		cin>>n;
	}
	
	return 0;
}
