/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2227
	Name: Walking Among Mountains I
	Number: 2227
	Date: 01/01/2014
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iterator>
#include <utility>
#include <list>

#define tint unsigned long long int
#define MAX_INT 2147483647

using namespace std;

int mapa[15][15];
int res[15][15];

void dp (int n) {
	int left, up, i, j;
	
	res[1][1] = 0;
	for (i=2; i<=n; i++) {
		if (mapa[i][1] > mapa[i-1][1]) {
			res[i][1] = mapa[i][1] - mapa[i-1][1] + res[i-1][1];
		} else {
			res[i][1] = res[i-1][1];
		}
		if (mapa[1][i] > mapa[1][i-1]) {
			res[1][i] = mapa[1][i] - mapa[1][i-1] + res[1][i-1];
		} else {
			res[1][i] = res[1][i-1];
		}
	}
	
	for (i=2; i<=n; i++) {
		for (j=2; j<=n; j++) {
			//up
			if (mapa[i][j] > mapa[i-1][j]) {
				up = mapa[i][j] - mapa[i-1][j] + res[i-1][j];
			} else {
				up = res[i-1][j];
			}
			//left
			if (mapa[i][j] > mapa[i][j-1]) {
				left = mapa[i][j] - mapa[i][j-1] + res[i][j-1];
			} else {
				left = res[i][j-1];
			}
			res[i][j] = min(up, left);
		}
	}
}

int main () {
	int n, i, j;
	tint a;
    
	cin>>n;
	for (i=1; i<=n; i++) {
		cin>>a;
		for (j=n; j>0; j--) {
			mapa[i][j] = a % 10;
			a /= 10;
		}
	}
	
	dp(n);
	
	scanf("%d %d", &i, &j);
	
	printf("%d\n", res[i][j]);
    
    return 0;
}
