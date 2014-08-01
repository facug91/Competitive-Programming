/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2139
	Name: Good Notes
	Number: 2139
	Date: 28/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;



int main () {
	string s1, s2;
	
	int i, j;
	
	while (cin>>s1>>s2) {
		
		j = 0;
		for (i=0; i<s2.length(); i++) {
			if (s2[i] == s1[j]) {
				j++;
			}
			if (j == s1.length()) break;
		}
		if (j == s1.length()) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		
	}
	
	return 0;
}
