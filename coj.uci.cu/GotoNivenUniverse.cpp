/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2645
	Name: Go to Niven Universe
	Number: 2645
	Date: 30/11/2013
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int b, m, e, i, total, aux;
string s;

int sumaDeDigitos () {
	aux = 0;
	for (i=0; i<s.size(); i++) {
		aux += (s[i] - '0');
	}
	return aux;
}

int main() {
	cin>>b;
	
	while (b) {
		cin>>s;
		
		m = sumaDeDigitos(); //de s como variable global
		e = 1;
		total = s[s.size()-1]-'0';
		
		for (i=s.size()-2; i>=0; i--) {
			e = (e * b) % m;
			total = (total + ((s[i] - '0') * e) % m) % m;
		}
		
		if (total == 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
		
		cin>>b;
	}
	
    return 0;
}
