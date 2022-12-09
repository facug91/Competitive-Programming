/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1839
	Name: A Funny Task
	Number: 1839
	Date: 31/10/2013
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main () {
	int t, n;
	
	cin>>t;
	
	while (t--){
		cin>>n;
		n = n*8+42;
		printf ("%d\n", n);
	}
	
}
