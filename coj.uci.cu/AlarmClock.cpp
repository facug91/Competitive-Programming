/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1064
	Name: Alarm Clock
	Number: 1064
	Date: 23/11/2013
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

int h1, m1, h2, m2, r;

int main () {

	cin>>h1>>m1>>h2>>m2;
	
	for(;(h1) || (m1) || (h2) || (m2);) {
		
		if (h2 < h1) {
			h2 += 24;
		} else {
			if ((m2 < m1) && (h1 == h2)){
				h2 += 24;
			}
		}
		
		r = ((h2 - h1) * 60) + (m2 - m1);
		
		printf("%d\n",r);
		
		cin>>h1>>m1>>h2>>m2;
	}
	
	return 0;
}
