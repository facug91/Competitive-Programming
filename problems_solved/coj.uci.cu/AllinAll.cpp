/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1028
	Name: All in All
	Number: 1028
	Date: 12/11/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

string s, t;
int i, j;

int main () {
	
	while (cin>>s) {
		
		cin>>t;
		i=0;
		for(j=0; (j<t.size()) && (i<s.size()); j++) {
			if (t[j] == s[i]) {
				i++;
			}
		}
		
		if (i >= s.size()) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	
	return 0;
}
