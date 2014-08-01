/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1551
	Name: TRI
	Number: 1551
	Date: 13/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>

#define tint unsigned long long int
#define MAX_INT 2147483647
#define MAX_DBL 1e+37

#define mod 1000000009

using namespace std;

int main () {
	int a, b, c, i;
	
	i = 1;
	while (cin>>a>>b>>c) {
		
		if (a + b == c) {
			printf("Case %d: %d+%d=%d\n", i, a, b, c);
		} else if (a == b + c) {
			printf("Case %d: %d=%d+%d\n", i, a, b, c);
		} else if (a - b == c) {
			printf("Case %d: %d-%d=%d\n", i, a, b, c);
		} else if (a == b - c) {
			printf("Case %d: %d=%d-%d\n", i, a, b, c);
		} else if (a * b == c) {
			printf("Case %d: %d*%d=%d\n", i, a, b, c);
		} else if (a == b * c) {
			printf("Case %d: %d=%d*%d\n", i, a, b, c);
		} else if (a / b == c) {
			printf("Case %d: %d/%d=%d\n", i, a, b, c);
		} else if (a == b / c) {
			printf("Case %d: %d=%d/%d\n", i, a, b, c);
		}
		
		i++;
	}
	
	return 0;
}
