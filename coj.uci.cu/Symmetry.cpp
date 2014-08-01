/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=
	Name: Symmetry
	Number: 1525
	Date: 28/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>

#define tint unsigned long long int

using namespace std;

int main () {
	tint n, m, res = 0, e = 1;
	
	cin>>n>>m;
	
	while ((n % 2 != 0) && (m % 2 != 0)) {
		res += e;
		n = (n-1)/2;
		m = (m-1)/2;
		e *= 4;
	}
	cout<<res<<endl;
	
	return 0;
}
