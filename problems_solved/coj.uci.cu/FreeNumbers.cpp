/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2916
	Name: Free Numbers
	Number: 2916
	Date: 05/06/2014
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int a, b;
 
int main() {
	
	while (scanf("%d %d", &a, &b) != EOF) {
		if (__gcd(a, b) == 1) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
} 
