/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2652
	Name: TIMSKO
	Number: 2652
	Date: 07/12/2014
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <iterator>
#include <utility>
#include <cmath>

using namespace std;

int g, b, k;

int main () {
	scanf("%d %d %d", &g, &b, &k);
	if (g % 2 == 1) {
		g--;
		k--;
	}
	if (g > b*2) {
		k -= (g - b*2);
		g = b*2;
	} else if (b*2 > g) {
		k -= (b - g/2);
		b = g/2;
	}
	if (k > 0) {
		k = (int) ceil(k/1.5);
		g -= k;
	}
	printf("%d\n", g/2);
	
	return 0;
}
