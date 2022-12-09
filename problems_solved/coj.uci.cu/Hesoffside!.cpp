/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1630
	Name: He's offside!
	Number: 1630
	Date: 12712/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <vector>

#define tint unsigned long long int
#define MAX_INT 2147483647

using namespace std;

struct cmp {
	bool operator() (int a, int b) {
		return (a > b);
	}
};

int main () {
	int a, b, i, aux;
	
	cin>>a>>b;
	while ((a) || (b)) {
		priority_queue<int, vector<int>, cmp> colaA, colaB;
		
		for (i=0; i<a; i++) {
			cin>>aux;
			colaA.push(aux);
		}
		
		for (i=0; i<b; i++) {
			cin>>aux;
			colaB.push(aux);
		}
		
		colaB.pop();
		if (colaA.top() < colaB.top()) {
			printf("Y\n");
		} else {
			printf("N\n");
		}
		
		cin>>a>>b;
	}
	
	return 0;
}
