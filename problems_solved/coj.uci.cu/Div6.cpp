/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1288
	Name: Div 6
	Number: 1288
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
	
	int t, sum, i;
	string n;
	
	cin>>t;
	
	for (;t--;) {
		cin>>n;
		if (n == "0") {
			printf("YES\n");
		} else if (n[n.size()-1] % 2 != 0) {
			printf("NO\n");
		} else {
			sum = 0;
			for (i=0; i<n.size(); i++) {
				sum += n[i];
			}
			if (sum % 3 == 0) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}
	
	return 0;
}
