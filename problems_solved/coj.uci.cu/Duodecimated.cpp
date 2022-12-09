/*
	By: facug91
	From: http://coj.uci.cu/24h/problem.xhtml?abb=2628
	Name: Duodecimated
	Number: 2628
	Date: 07/12/2013
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

struct cmp {
	bool operator() (const char &a, const char &b) {
		return (a > b);
	}
};

int i;
string num, add;
unsigned long long int res, j;

int main () {
	
	while (getline(cin, num)) {
		getline(cin, add);
		priority_queue<char, vector<char>, cmp > cola;
		
		for (i=0; i<add.length(); i++) {
			cola.push(add[i]);
		}
		
		if (num[num.length()-1] != '?') {
			res = (num[num.length()-1]-'0');
		} else {
			if (!cola.empty()) {
				res = cola.top()-'0';
				cola.pop();
			} else {
				res = 11;
			}
		}
		
		j = 12;
		for (i=num.length()-2; i>=0; i--) {
			if (num[i] != '?') {
				res += ((num[i]-'0')*j);
			} else {
				if (!cola.empty()) {
					res += ((cola.top()-'0')*j);
					cola.pop();
				} else {
					res += (11*j);
				}
			}
			
			j *= 12;
		}
		
		printf("%llu\n", res);
	}
	
	return 0;
}
