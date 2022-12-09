/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=8
	Name: Triangle and Rhomboid
	Number: 1778
	Date: 02/12/2013
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <utility>

using namespace std;

int t, a, b;
double res;

int main() {
	cin>>t;
	
	for (;t--;) {
		cin>>a>>b;
		
		res = a * b * 0.1875;
		
		printf("%.8f\n",res);
	}
	
    return 0;
}
