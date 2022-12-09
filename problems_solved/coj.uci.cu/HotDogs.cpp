/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2115
	Name: Hot Dogs
	Number: 2115
	Date: 28/11/2013
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

int h, p;

int main () {
	
	for(;cin>>h>>p;) {
		printf("%.2f\n",((h+0.0) / (p+0.0)));
	}
	
	return 0;
}
