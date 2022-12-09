/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1079
	Name: Sums in a Triangle I
	Number: 1079
	Date: 03/12/2013
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int t, h, i, j;
int matriz[100][100];

int main() {
	cin>>t;
	
	for (;t--;) {
		cin>>h;
		
		for(i=0; i<h; i++) {
			for (j=0; j<i+1; j++) {
				cin>>matriz[i][j];
			}
		}
		
		for (i=h-2; i>=0; i--) {
			for (j=0; j<i+1; j++) {
				matriz[i][j] += max(matriz[i+1][j],matriz[i+1][j+1]);
			}
		}
		
		printf("%d\n",matriz[0][0]);
		
	}
	
    return 0;
}
