/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1297
	Name: Divisibility by 495
	Number: 1297
	Date: 12/11/2013 
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int main () {
	
	int t, len, once, nueve, i;
	string s;
	
	cin>>t;
	
	for (;t--;) {
		
		cin>>s;
		
		len = s.size();
		once = 0;
		nueve = 0;
		
		if ((s[len-1] == '0') || (s[len-1] == '5')) {
			for (i=len-1; i>0; i-=2) {
				once += (s[i]-'0') - (s[i-1]-'0');
				nueve += (s[i]-'0') + (s[i-1]-'0');
			}
			if (len%2 == 1) {
				once += (s[0]-'0');
				nueve += (s[0]-'0');
			}
			
			if ((nueve % 9 == 0) && (once % 11 == 0)) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		} else {
			printf("NO\n");
		}
	}
	
	return 0;
}
