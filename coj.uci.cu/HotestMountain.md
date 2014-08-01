/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1484
	Name: Hotest Mountain
	Number: 1484
	Date: 15/11/2013
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <set>
#include <iterator>
#include <climits>
#include <cmath>
#define x first
#define y second

using namespace std;

int n, i, hp;
double hn, t;

int main () {
	cin>>n;
	
	hn = -1.0;
	for (i=1; i<=n; i++) {
		cin>>t;
		if (hn <= t) {
			hn = t;
			hp = i;
		}
	}
	
	printf("%d\n",hp);
	
	return 0;
}
