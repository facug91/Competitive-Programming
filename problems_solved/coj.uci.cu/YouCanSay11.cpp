/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1102
	Name: You Can Say 11
	Number: 1102
	Date: 01/11/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int main () {
	
	string number;
	int i, result, aux;
	
	getline(cin,number);
	while (number.compare("0")) {
		i = 0;
		result = 0;
		
		if (number.length()%2 == 0) {
			while (i < number.length()) {
				result -= (number.at(i)-'0');
				i++;
				
				result += (number.at(i)-'0');
				i++;
			}
			
		} else {
			while (i < number.length()-1) {
				result += (number.at(i)-'0');
				i++;
				
				result -= (number.at(i)-'0');
				i++;
			}
			result += (number.at(i)-'0');
		}
		if (result % 11 == 0) {
			cout<<number<<" is a multiple of 11."<<endl;
		} else {
			cout<<number<<" is not a multiple of 11."<<endl;
		}
		
		
		getline(cin,number);
	}
	
	return 0;
}
