/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1658
	Name: Longest Increasing Subsequence (LIS)
	Number: 1658
	Date: 28/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include <utility>
#include <queue>

#define tint unsigned long long int

using namespace std;

int num[1001], cant[1001];

int main () {
    int k, n, i, j, nmax;
	
	cin>>k;
	
	while (k--) {
		
		cin>>n;
		
		for (i=0; i<n; i++) {
			cin>>num[i];
		}
		
		for (i=0; i<n; i++) cant[i] = 1;
		nmax = 1;
		for (i=1; i<n; i++) {
			for (j=0; j<i; j++) {
				if (cant[j] >= cant[i] && num[j] < num[i]) {
					cant[i] = cant[j]+1;
				}
			}
			if (nmax < cant[i]) nmax = cant[i];
		}
		
		cout<<nmax<<endl;
		
	}
	
	return 0;
}
