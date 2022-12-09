/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2145
	Name: Beauty Contest
	Number: 2145
	Date: 13/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <queue>

#define tint unsigned long long int
#define MAX_INT 2147483647
#define MAX_DBL 1e+37

#define mod 1000000009

using namespace std;

int main () {
	int n, g, sum, i, j, mi, ma;
	
	cin>>n;
	
	for (i=1; i<=n; i++) {
		sum = 0;
		mi = MAX_INT;
		ma = 0;
		for (j=0; j<10; j++) {
			cin>>g;
			sum += g;
			if (mi > g) mi = g;
			if (ma < g) ma = g;
		}
		
		printf("%d %d\n", i, sum-mi-ma);
		
		
	}
	
	return 0;
}
