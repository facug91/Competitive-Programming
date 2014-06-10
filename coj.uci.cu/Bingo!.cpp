/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1240
	Name: Bingo!
	Number: 1240
	Date: 08/11/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <list>
#include <iterator>
#include <cstdlib>
#include <set>

using namespace std;

int main () {
	
	int n, b, aux, act;
	list<int> sobrantes;
	set<int> total;
	list<int>::iterator itr;
	
	cin>>n>>b;
	
	
	while ((n) && (b)) {
		for (;b--;) {
			cin>>aux;
			sobrantes.push_back(aux);
		}
		
		b = sobrantes.size();
		for (;b--;) {
			act = sobrantes.front();
			for (itr = sobrantes.begin(); itr != sobrantes.end(); itr++) {
				total.insert(abs(act - *itr));
			}
			sobrantes.pop_front();
		}
		
		if (total.size() == n+1) {
			printf("Y\n");
		} else {
			printf("N\n");
		}
		
		total.clear();
		
		cin>>n>>b;
	}
	
	
	
	
	return 0;
}
