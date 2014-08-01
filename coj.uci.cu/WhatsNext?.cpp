/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1445
	Name: What's Next?
	Number: 1445
	Date: 23/11/2013
*/

#include <cstdio>

using namespace std;

int a1, a2, a3;

int main () {

	scanf("%d %d %d", &a1, &a2, &a3);
	
	for(;(a1) || (a2) || (a3);) {
		
		if ((a1) && (a2) && (a3) && (a2 * (a2 / a1) == a3)) {
			printf("GP %d\n", (a3 * (a2 / a1)));
		} else {
			printf("AP %d\n", (a3 + (a2 - a1)));
		}
		
		scanf("%d %d %d", &a1, &a2, &a3);
	}
	
	return 0;
}
