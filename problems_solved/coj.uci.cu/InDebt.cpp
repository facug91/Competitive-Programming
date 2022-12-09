/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2060
	Name: In Debt
	Number: 2060
	Date: 11/12/2013
*/

#include <stdio.h>
using namespace std;
int main () {
	short n, k, b, a;
	scanf("%hd", &n);
	while (n != -1){
		a = 0;
		k = 0;
		while (n--) {
			scanf("%hd", &b);
			k += b;
			if(k % 100 == 0) a++;
		}
		printf("%hd\n",a);
		scanf("%hd", &n);
	}
}
