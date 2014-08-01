/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2634
	Name: Birthday Statistics
	Number: 2634
	Date: 03/12/2013
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <utility>
#include <algorithm>
#define tint unsigned long long int

using namespace std;

int t, id, i, m;
string s;
int meses[13];

int main() {
	cin>>t;
	memset(meses,0,sizeof(meses));
	
	for (;t--;) {
		cin>>id>>s;
		i = 0;
		while (s[i] != '/') i++;
		i++;
		m = s[i] - '0';
		i++;
		if (s[i] != '/') {
			m *= 10;
			m += (s[i] - '0');
		}
		meses[m]++;
	}
	for (i=1; i<=12; i++) {
		printf("%d %d\n", i, meses[i]);
	}
	
    return 0;
}
