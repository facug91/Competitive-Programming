/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2413
	Name: Div 5
	Number: 2413
	Date: 11/11/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <list>
#include <iterator>
#include <cstdlib>
#include <set>

using namespace std;

int main () {
	int t;
	string n;
	
	cin>>t;
	
	for (;t--;) {
		cin>>n;
		
		if ((n[n.size()-1]+2) % 5) {
			printf("NO\n");	
		} else {
			printf("YES\n");
		}
	}
	
	
	return 0;
}
