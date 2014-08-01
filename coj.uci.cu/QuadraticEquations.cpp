/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2148
	Name: Quadratic Equations
	Number: 2148
	Date: 03/12/2013
*/

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int n, a, b, c;

int main() {
	cin>>n;
	
	while(n--) {
		cin>>a>>b>>c;
		if ((b*b)-(4*a*c) < 0) {
			printf("NO\n");
		} else {
			printf("SI\n");
		}
	}
	
    return 0;
}
