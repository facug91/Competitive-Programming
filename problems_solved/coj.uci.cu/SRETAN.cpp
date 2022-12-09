/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2654
	Name: SRETAN
	Number: 2654
	Date: 07/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int main () {
	char c[] = {'4', '7'};
	int k, i, j, p;
	string res;
	scanf("%d", &k);
	
	i=0;
	for (p=2; p<k; k-=p, p*=2) i++;
	
	k--;
	if (!k) {
		res = "";
		for (j=0; j<i+1; j++) res += '4';
	} else {
		res = "";
		while (k != 0) {
			res = c[k%2] + res;
			k /= 2;
			i--;
		}
		for (j=0; j<i+1; j++) res = '4' + res;
	}
	
	cout<<res<<endl;
	
	return 0;
}
