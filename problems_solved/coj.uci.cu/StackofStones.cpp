/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2151
	Name: Stack of Stones
	Number: 2151
	Date: 13/12/2013
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

#define mod 1000000009

using namespace std;

int main () {
	int t, n, s, sum;
	
	cin>>t;
	
	while (t--) {
		
		priority_queue<int> cola;
		
		cin>>n;
		
		while (n--) {
			cin>>s;
			cola.push(s);
		}
		
		sum = 0;
		cola.pop();
		
		while (!cola.empty()) {
			sum += cola.top();
			cola.pop();
		}
		
		printf("%d\n", sum);
		
		
		
	}
	
	return 0;
}
