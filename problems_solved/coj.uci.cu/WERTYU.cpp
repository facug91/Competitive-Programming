/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1665
	Name: WERTYU
	Number: 1665
	Date: 05/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

char c[100];

void init () {
	c['1'] = '`';
	c['2'] = '1';
	c['3'] = '2';
	c['4'] = '3';
	c['5'] = '4';
	c['6'] = '5';
	c['7'] = '6';
	c['8'] = '7';
	c['9'] = '8';
	c['0'] = '9';
	c['-'] = '0';
	c['='] = '-';
	c['W'] = 'Q';
	c['E'] = 'W';
	c['R'] = 'E';
	c['T'] = 'R';
	c['Y'] = 'T';
	c['U'] = 'Y';
	c['I'] = 'U';
	c['O'] = 'I';
	c['P'] = 'O';
	c['['] = 'P';
	c[']'] = '[';
	c['\\'] = ']';
	c['S'] = 'A';
	c['D'] = 'S';
	c['F'] = 'D';
	c['G'] = 'F';
	c['H'] = 'G';
	c['J'] = 'H';
	c['K'] = 'J';
	c['L'] = 'K';
	c[';'] = 'L';
	c['\''] = ';';
	c['X'] = 'Z';
	c['C'] = 'X';
	c['V'] = 'C';
	c['B'] = 'V';
	c['N'] = 'B';
	c['M'] = 'N';
	c[','] = 'M';
	c['.'] = ',';
	c['/'] = '.';
	c[' '] = ' ';
}

int main() {
	
	init();
	string s;
	while(getline(cin, s)) {
		for (int i=0; i<s.size(); i++) {
			printf("%c", c[s[i]]);
		}
		printf("\n");
	}
	
    return 0;
}
