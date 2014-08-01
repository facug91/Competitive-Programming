/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2647
	Name: Here the Candies
	Number: 2647
	Date: 28/12/2013
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <utility>
#include <iterator>
#include <vector>

#define tint unsigned long long int
#define MAX_INT 2147483647

using namespace std;

int main () {
	tint c, n, m;
	
	cin>>c;
	cin>>m;
	while (c--) {
		cin>>n;
		printf("%llu\n", ((n%m)*(n%m))%m);
	}
	
	return 0;
}
