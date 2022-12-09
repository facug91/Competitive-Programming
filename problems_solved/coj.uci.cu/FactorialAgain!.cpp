/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1238
	Name: Factorial Again!
	Number: 1238
	Date: 15/11/2013
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <set>
#include <iterator>

using namespace std;

int factorial[] = {120,24,6,2,1};
string n;
int total, i, j;

int main () {
	
	cin>>n;
	for(;n[0]!='0';) {
		total = 0;
		j = 4;
		for (i=n.size()-1; i>=0; i--){
			total += (n[i]-'0') * factorial[j];
			j--;
		}
		
		printf("%d\n",total);
		cin>>n;
	}
	
	return 0;
}
