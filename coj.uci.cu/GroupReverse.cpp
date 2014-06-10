/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1177
	Name: Group Reverse
	Number: 1177
	Date: 21/11/2013
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <iterator>

using namespace std;

int g, i, j;
string s, resultado;
string::reverse_iterator itrb, itre;

int main () {
	
	cin>>g;
	
	while (g) {
	
		cin>>s;
		
		resultado = "";
		
		itrb = s.rbegin();
		while (itrb != s.rend()) {
			itre = itrb;
			for (j=0; j<s.size()/g; j++) {
				itre++;
			}
			resultado = string(itrb,itre) + resultado;
			itrb = itre;
		}
		
		cout<<resultado<<endl;
		
		cin>>g;
	}
	
	return 0;
}
