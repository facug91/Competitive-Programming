/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1259
	Name: Div 4 Base 3
	Number: 1259
	Date: 03/12/2013
*/

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

int t, n, i, e;
string s;

int main() {
	cin>>t;
	
	while(t--) {
		cin>>s;
		n = 0;
		e = 1;
		for (i=s.size()-1; i>=0; i--) {
			n = (n + ((s[i]-'0') * e)) % 4;
			e = (e*3) % 4;
		}
		(n==0)?printf("YES\n"):printf("NO\n");
	}
	
    return 0;
}
