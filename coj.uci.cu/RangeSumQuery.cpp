/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2637
	Name: Range Sum Query
	Number: 2637
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

using namespace std;

tint sum[100001];

int main () {
	int t, n, q, i, j, k, f;
	tint res;
	
	cin>>t;
	
	while (t--) {
		cin>>n>>q;
		cin>>sum[0];
		for (k=1; k<n; k++) {
			cin>>sum[k];
			sum[k] += sum[k-1];
		}
		
		for (k=0; k<q; k++) {
			cin>>i>>j;
			if (i == 0) {
				printf("%llu\n", sum[j]);
			} else {
				printf("%llu\n", sum[j]-sum[i-1]);
			}
		}
		
		if (t) {
			printf("\n");
		}
	}
	
	return 0;
}
