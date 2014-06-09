/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2655
	Name: AVION
	Number: 2655
*/

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

string s;
int i, j;
bool es, nunca;

int main() {
	nunca = true;
	for (i=1; i<=5; i++) {
		cin>>s;
		j=0;
		es = false;
		while ((j<s.size()-2) && (!es)) {
			while ((j<s.size()-2) && (s[j] != 'F')) j++;
			if ((s[j] == 'F') && (s[j+1] == 'B') && (s[j+2] == 'I')) es = true;
			else j++;
		}
		if (es) {
			if (nunca) {
				printf("%d", i);
				nunca = false;
			} else {
				printf(" %d", i);
			}
		}
	}
	if (nunca) {
		printf("HE GOT AWAY!\n");
	} else {
		printf("\n");
	}
	
    return 0;
}
