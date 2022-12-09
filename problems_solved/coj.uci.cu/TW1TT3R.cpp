/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2696
	Name: TW1TT3R
	Number: 2696
	Date: 18/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>

#define tint unsigned long long int
#define MAX_INT 2147483647
#define MAX_DBL 1e+37

using namespace std;

set<int> usuario[1001];

int main () {
	int n, m, a, b, i, max = 0;
	
	cin>>n>>m;
	
	for (i=0; i<m; i++) {
		cin>>a>>b;
		usuario[a].insert(b);
		if (usuario[a].size() > max) max = usuario[a].size();
	}
	
	i = 1;
	while (usuario[i].size() != max) {
		i++;
	}
	printf("%d", i);
	for (i=i+1;i<=n; i++) {
		if (usuario[i].size() == max) {
			printf(" %d", i);
		}
	}
	printf("\n");
	
	return 0;
}
