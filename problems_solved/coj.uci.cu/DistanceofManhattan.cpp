/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1842
	Name: Distance of Manhattan
	Number: 1842
	Date: 04/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int t, a, b, c, d;

int main() {
	cin>>t;
	
	for (;t--;) {
		cin>>a>>b>>c>>d;
		printf("%d\n", (abs(a-c)+abs(b-d)));
	}
	
    return 0;
}
