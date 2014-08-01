/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1808
	Name: Hamming Distance
	Number: 1808
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



int main () {
	string a, b;
	int i, j, cont;
	
	cin>>a;
	while (a[0] != 'X') {
		cin>>b;
		
		cont = 0;
		for (i=0; i<a.length(); i++) {
			if (a[i] != b[i]) cont++;
		}
		
		cout<<"Hamming distance is "<<cont<<"."<<endl;
		
		cin>>a;
	}
	
    return 0;
}
