/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2150
	Name: Balanced Words II
	Number: 2150
	Date: 13/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>

#define tint unsigned long long int
#define MAX_INT 2147483647
#define MAX_DBL 1e+37

#define mod 1000000009

using namespace std;

int main () {
	int c, l1, l2, u1, u2, i, len;
	string s;
	
	cin>>c;
	
	while (c--) {
		cin>>s;
		
		l1 = l2 = u1 = u2 = 0;
		
		for (i=0; i<s.length()/2; i++) {
			if (s[i] <= 'Z') {
				u1++;
			} else {
				l1++;
			}
		}
		
		if (s.length() % 2 == 0) {
			len = s.length()/2;
		} else {
			len = (s.length()/2) + 1;
		}
		
		for (i=s.length()-1; i>=len; i--) {
			if (s[i] <= 'Z') {
				u2++;
			} else {
				l2++;
			}
		}
		
		if ((l1 == l2) && (u1 == u2)) {
			printf("SI\n");
		} else {
			printf("NO\n");
		}
	}
	
	return 0;
}
