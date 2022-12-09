/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1176
	Name: Ternary
	Number: 1176
	Date: 21/11/2013
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <iterator>

using namespace std;

int n;
string base3;
char c;

int main () {
	
	cin>>n;
	
	while (n >= 0) {
		base3 = "";
		while (n != 0) {
			c = (n % 3) + '0';
			base3 = c + base3;
			n /= 3;
		}
		
		cout<<base3<<endl;
		
		cin>>n;
	}
	
	return 0;
}
