/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2281
	Name: Encoded Message
	Number: 2281
	Date: 12/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>

#define tint unsigned long long int
#define MAXC 100100

using namespace std;

int main () {
	int t, i, j, len;
	string s, res;
	cin>>t;
	
	while (t--) {
		cin>>s;
		res = "";
		len = (int) sqrt(s.length());
		for (i=len-1; i>=0; i--) {
			for (j=i; j<s.length(); j+=len) {
				res += s[j];
			}
		}
		cout<<res<<endl;
	}
	
	return 0;
}
