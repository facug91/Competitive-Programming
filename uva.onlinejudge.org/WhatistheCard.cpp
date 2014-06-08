/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=18&page=show_problem&problem=1587
	Name: What is the Card?
	Number: 10646
*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <iterator>
#include <utility>
#include <list>
#include <stack>
#include <iomanip>
#include <bitset>

#define MAX_INT 2147483647
#define MAX_LONG 9223372036854775807ll
#define MAX_ULONG 18446744073709551615ull
#define MAX_DBL 1.7976931348623158e+308
#define EPS 1e-9
//const long double PI = 2*acos(0);

#define INF 1000000000
//
using namespace std;

int t, i, j, y, x;
stack< char* > middle1;
deque< char* > middle2;


int main() {
	
	scanf("%d", &t);
	
	for (int it=1; it<=t; it++) {
		
		if (it != 1) {
			while (!middle1.empty()) middle1.pop(); 
			while (!middle2.empty()) middle2.pop_back(); 
		}
		
		char * s;
		
		for (i=0; i<27; i++) {
			s = new char[3];
			scanf("%s", s);
			middle1.push(s);
		}
		
		for (i=0; i<25; i++) {
			s = new char[3];
			scanf("%s", s);
			middle2.push_front(s);
		}
		
		y = 0;
		for (i=0; i<3 && !middle1.empty(); i++) {
			
			char c = middle1.top()[0];
			
			if ((c >= '0') && (c <= '9')) x = c - '0';
			else x = 10;
			
			y += x;
			
			x = 11 - x;
			
			for (j=0; j<x && !middle1.empty(); j++) 
				middle1.pop();
			
		}
		
		while (!middle1.empty()) {
			middle2.push_back(middle1.top());
			middle1.pop();
		}
		
		for (i=0; i<y-1; i++) 
			middle2.pop_back();
		
		printf("Case %d: %s\n", it, middle2.back());
		
		
		
	}
	
	return 0;
} 
