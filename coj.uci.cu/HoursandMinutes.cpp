/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2124
	Name: Hours and Minutes
	Number: 2124
	Date: 08/11/2013
*/

#include <iostream>
#include <cstdio>

using namespace std;

int r[181] ={'Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y','N','N','N','N','N','Y'};

int main() {
	int d;
	while(cin >> d){
		printf("%c\n",r[d]);
	}
}
