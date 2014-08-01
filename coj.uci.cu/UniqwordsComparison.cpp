/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2700
	Name: Uniqwords Comparison
	Number: 2700
	Date: 18/12/2013
*/

#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring>
#include <string>

using namespace std; 

int main(){ 
    int i, j;
	
	string s1, s2;
	string r1 = "", r2 = "", r3 = "";
	
	cin>>s1;
	cin>>s2;
	
	i = j = 0;
	while ((i < s1.length()) && (j < s2.length())) {
		if (s1[i] == s2[j]) {
			r3 += s1[i];
			i++;
			j++;
		} else if (s1[i] > s2[j]) {
			r2 += s2[j];
			j++;
		} else {
			r1 += s1[i];
			i++;
		}
	}
	
	if (i < s1.length()) {
		r1 += s1.substr(i,s1.length());
	}
	if (j < s2.length()) {
		r2 += s2.substr(j,s2.length());
	}
	
	cout<<"First:"<<r1<<endl;
	cout<<"Second:"<<r2<<endl;
	cout<<"First&Second:"<<r3<<endl;
	
	return 0;
}
