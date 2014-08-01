/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1478
	Name: Basic Edit Distance
	Number: 1478
	Date: 28/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int cambios[501][501];

int main () {
	string s1, s2;
	int i, j;
	
	cin>>s1>>s2;
	
	for (i=0; i<=s1.length(); i++) cambios[i][0] = i;
	for (j=0; j<=s2.length(); j++) cambios[0][j] = j;
	
	for (i=1; i<=s1.length(); i++) {
		for (j=1; j<=s2.length(); j++) {
			if (s1[i-1] == s2[j-1]) {
				cambios[i][j] = cambios[i-1][j-1];
			} else {
				cambios[i][j] = min(cambios[i-1][j], min(cambios[i][j-1], cambios[i-1][j-1]))+1;
			}
		}
	}
	
	cout<<cambios[s1.length()][s2.length()]<<endl;
	
	return 0;
}
