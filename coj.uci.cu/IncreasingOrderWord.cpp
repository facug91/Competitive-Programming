/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=1485
	Name: Increasing Order Word
	Number: 1485
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

struct cmp {

	bool operator() (char c1, char c2) {
		return (c1 > c2);
	}
};

string s;
int i;
priority_queue<char, vector<char>, cmp> cola;

int main () {
	
	cin>>s;
	
	for (i=0; i<s.size(); i++) {
		cola.push(s[i]);
	}
	for (i=0; i<s.size(); i++) {
		printf("%c",cola.top());
		cola.pop();
	}
	
	printf("\n");
	
	return 0;
}
