/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2146
	Name: Counting Diagonals
	Number: 2146
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
	int d, v;
	scanf("%d %d", &d, &v);
	
	if (d == ((v*(v-1))/2)-v) {
		printf("yes\n");
	} else {
		printf("no\n");
	}
	
	
	return 0;
}
