/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1538
	Name: Financial Management II
	Number: 1538
	Date: 03/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstring>

using namespace std;

int t, i, j;
double mes, total;

string giveFormat(double d) {

	string s;
	char s1[1000];
	
	sprintf (s1, "%.2lf", d);
	s = string(s1);
	
	for (int i=s.size()-6; i>0; i-=3) {
		s.insert(i, ",");
	}
	return s;
}

int main() {
	cin>>t;
	
	for (i=1; i<=t; i++) {
		total = 0.0;
		for(j=0; j<12; j++) {
			cin>>mes;
			total += mes;
		}
		total /= 12.0;
		
		cout<<i<<" $"<<giveFormat(total)<<"\n";
	}
	
    return 0;
}
