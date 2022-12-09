/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=
	Name: Displacing Characters
	Number: 2147
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
	
	int t, k, aux;
	string s, res;
	
	cin>>t;
	
	while (t--) {
		cin>>s>>k;
		
		aux = k % s.length();
		res = s.substr(s.length()-aux, s.length()) + s.substr(0, s.length()-aux);
		
		cout<<res<<endl;
	}
	
	return 0;
}
