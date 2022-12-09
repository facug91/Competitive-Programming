/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2698
	Name: A+B=C
	Number: 2698
	Date: 18/12/2013
*/

#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring>
#include <string>

using namespace std; 

int main(){ 
    
	string s;
	int res = 0, i;
	cin>>s;
	for (i=0; i<s.length(); i++) {
		res += (s[i]-'A'+1);
	}
	printf("%d\n", res);
}
