/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2149
	Name: Balanced Words I
	Number: 2149
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
	int c, l, u, i;
	string s;
	
	cin>>c;
	
	while (c--) {
		cin>>s;
		
		l = u = 0;
		
		for (i=0; i<s.length(); i++) {
			if (s[i] <= 'Z') {
				u++;
			} else {
				l++;
			}
		}
		
		if (l == u) {
			printf("SI\n");
		} else {
			printf("NO\n");
		}
	}
	
	return 0;
}
