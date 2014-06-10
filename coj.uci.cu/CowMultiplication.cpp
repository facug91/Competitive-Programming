/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1188
	Name: Cow Multiplication
	Number: 1188
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
	string a, b;
	int i, j, total = 0;
	cin>>a>>b;
	
	for (i=0; i<a.size(); i++) {
		for (j=0; j<b.size(); j++) {
			total += ((a[i]-'0') * (b[j]-'0'));
		}
	}
	
	printf("%d\n",total);
	
	return 0;
}
