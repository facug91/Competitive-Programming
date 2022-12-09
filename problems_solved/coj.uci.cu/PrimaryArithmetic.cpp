/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1603
	Name: Primary Arithmetic
	Number: 1603
	Date: 18/11/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
//18:25 - 18:38
using namespace std;

string n1, n2; 
int i, j, total;
bool carry;

int main () {
	cin>>n1>>n2;
	
	while ((n1[0] != '0') || (n2[0] != '0')) {
		if (n1.size() > n2.size()) swap(n1, n2);
		j = n2.size()-1;
		total = 0;
		carry = false; 
		for (i=n1.size()-1; i>=0; i--) {
			if (!carry) {
				if ((n1[i]-'0') + (n2[j]-'0') > 9) {
					total++;
					carry = true;
				}
			} else {
				carry = false;
				if ((n1[i]-'0') + (n2[j]-'0') + 1 > 9) {
					total++;
					carry = true;
				}
			}
			j--;
		}
		while ((j >= 0) && (carry)) {
			carry = false;
			if ((n2[j]-'0') + 1 > 9) {
				total++;
				carry = true;
			}
			j--;
		}
		
		if (total) {
			if (total - 1) {
				printf("%d carry operations.\n",total);
			} else {
				printf("%d carry operation.\n",total);
			}
		} else {
			printf("No carry operation.\n");
		}
		
		cin>>n1>>n2;
	}
	
	return 0;
}
