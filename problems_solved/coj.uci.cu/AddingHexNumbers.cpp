/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2465
	Name: Adding Hex Numbers
	Number: 2465
	Date: 17/11/2013
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <algorithm>

//11:47
using namespace std;

int t, i, j, total;
char c;
bool carry;
string s1, s2;
int hexadecimalADecimal[100];

int main () {
	
	memset(hexadecimalADecimal,0,sizeof(hexadecimalADecimal));
	
	for (c='0'; c<='9'; c++) {
		hexadecimalADecimal[c] = (c - '0');
	}
	for (c='A'; c<='F'; c++) {
		hexadecimalADecimal[c] = (c - 55);
	}
	
	cin>>t;
	
	for (;t--;) {
	
		cin>>s1>>s2;
		
		total = 0;
		
		if (s1.size() > s2.size()) swap(s1, s2); //siempre el s1 es menor o igual a s2
		
		j = s2.size()-1;
		
		carry = false;
		
		for (i=s1.size()-1; i>=0; i--) {
			if (!carry) {
				if ((hexadecimalADecimal[s1[i]] + hexadecimalADecimal[s2[j]]) > 15) {
					carry = true;
					total++;
				}
			} else {
				carry = false;
				if ((hexadecimalADecimal[s1[i]] + hexadecimalADecimal[s2[j]] + 1) > 15) {
					carry = true;
					total++;
				} 
			}
			j--;
		}
		while ((carry) && (j >= 0)) {
			if ((hexadecimalADecimal[s2[j]] + 1) > 15) {
				total++;
			} else {
				carry = false;
			}
			j--;
		}
		
		printf("%d\n", total);
	}
	return 0;
}
