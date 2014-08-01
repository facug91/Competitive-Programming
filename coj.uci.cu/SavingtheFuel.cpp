/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=
	Name: Saving the Fuel
	Number: 2144
	Date: 13/12/2014
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <queue>

#define tint unsigned long long int
#define MAX_INT 2147483647
#define MAX_DBL 1e+37

using namespace std;

struct cmp {
	bool operator() (int a, int b) {
		return a > b;
	}
};

int main () {
	int tc, n, d, p, i, sum;
	string t;
	
	cin>>tc;
	
	while (tc--) {
		cin>>n>>d>>t;
		
		priority_queue<int> cola1;
		priority_queue<int, vector<int>, cmp> cola2;
		
		if (t[0] == 'i') {
			for (i=0; i<n; i++) {
				cin>>p;
				cola2.push(p);
			}
			
			sum = 0;
			for (i=0; i<d; i++) {
				sum += cola2.top();
				cola2.pop();
			}
			
			printf("%d\n", sum);
		} else {
			for (i=0; i<n; i++) {
				cin>>p;
				cola1.push(p);
			}
			
			sum = 0;
			for (i=0; i<d; i++) {
				sum += cola1.top();
				cola1.pop();
			}
			
			printf("%d\n", sum);
		}
		
		
		
		
	}
	
	return 0;
}
