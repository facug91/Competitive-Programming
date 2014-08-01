/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2630
	Name: Too Many Robots
	Number: 2630
	Date: 21/11/2013
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

long long int k[6];
int i, j, l, m;
long long int total;

int main () {
	
	for (m=1; m<=5; m++) {
		total = 0ll;
		memset(k,0ll,sizeof(k));
		k[m] = 1;
		for(i=m; i>1; i--) {
			while (k[i]) {
				for(l=0; l<i; l++) {
					for (j=1; j<i; j++) {
						k[j] += k[j+1];
						
					}
				}
				total++;
				k[i]--;
			}
		}
		total += k[1];
		printf("If a size-%d robot went on a rampage, we would have to destroy at least %llu robots.\n", m, total);
	}
	
	return 0;
}
