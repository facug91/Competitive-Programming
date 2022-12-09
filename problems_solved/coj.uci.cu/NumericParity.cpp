/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1059
	Name: Numeric Parity
	Number: 1059
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
	int n, paridad;
	string s;
	cin>>n;
	
	while (n) {
		paridad = 0;
		s = "";
		
		while (n) {
			s = (char) ((n%2)+'0') + s;
			if (n%2) {
				paridad++;
			}
			n /= 2;
		}
		
		cout<<"The parity of "<<s<<" is "<<paridad<<" (mod 2)."<<endl;
		
		cin>>n;
	}
	
	
	return 0;
}
