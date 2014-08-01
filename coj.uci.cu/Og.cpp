/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1933
	Name: Og
	Number: 1933
	Date: 15/11/2013
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int l, r;
double hn, t;

int main () {
	cin>>l>>r;
	
	while ((l) && (r)) {
		l += r;
		printf("%d\n",l);
		cin>>l>>r;
	}
	
	return 0;
}
