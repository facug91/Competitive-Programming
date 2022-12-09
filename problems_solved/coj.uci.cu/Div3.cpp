/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1051
	Name: Div 3
	Number: 1051
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
	
	int n, result;
	
	cin>>n;
	
	if (n % 3 == 0) {
		result = n - (n / 3);
	} else if (n % 3 == 1) {
		result = (n - 1) - ((n - 1) / 3);
	} else {
		result = (n - ((n + 1) / 3));
	}
	
	cout<<result<<endl;
	
	return 0;
}
