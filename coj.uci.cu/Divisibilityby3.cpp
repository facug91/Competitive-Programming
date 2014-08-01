/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2642
	Name: Divisibility by 3
	Number: 2642
	Date: 29/11/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int n, i, total;
string s;

int main () {
	scanf("%d",&n);
	
	for (;n--;) {
		cin>>s;
		total = 0;
		for (i=s.size()-1; i>=0; i--) {
			if (s[i] == '1') {
				if (i % 2 == 0) {
					total += 1;
				} else {
					total += 2;
				}
			}
		}
		if (total % 3 == 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	
	
	return 0;
}
