/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2623
	Name: Super Encryption
	Number: 2623
	Date: 17/12/2014
*/

#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring>
#include <string>

using namespace std; 

int main(){ 
    string s, mitad1, mitad2, res;
	
	cin>>s;
	
	if (s.length() % 2 == 0) {
		res = mitad1.assign(s.rbegin()+(s.length()/2), s.rend()) + mitad2.assign(s.rbegin(), s.rend()-(s.length()/2));
	} else {
		res = mitad1.assign(s.rbegin()+(s.length()/2+1), s.rend()) + s[s.length()/2] + mitad2.assign(s.rbegin(), s.rend()-(s.length()/2+1));
	}
	
	cout<<res<<endl;
	
	return 0;
}
