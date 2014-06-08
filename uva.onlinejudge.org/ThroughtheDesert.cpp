/*
	By: facug91
	From: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3086
	Name: Through the Desert
	Number: 11935
	
	Solved with binary search
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

int value[55], dist[55], cant;
char action[55];
double ans;

bool simulate (double fuel) {
	double c = ((double) value[0]) / 100.0;
	int d = 0, leaks = 0;
	double f = fuel;
	
	for (int i=1; i<cant-1; i++) {
		
		f -= (((double)(dist[i]-d))*c);
		
		if (f < 0.0) return false;
		d = dist[i];
		
		switch (action[i]) {
			case 'c':
				c = (((double) value[i]) / 100.0) + ((double) leaks);
				break;
			case 's':
				f = fuel;
				break;
			case 'l':
				leaks++;
				c += 1.0;
				break;
			case 'm':
				c -= ((double) leaks);
				leaks = 0;
				break;
		}
		
	}
	
	f -= (((double)(dist[cant-1]-d))*c); //llega al Goal
	if (f < 0.0) return false;
	else return true;
}

void binary_search () {
	
	double lo = 0.0, hi = 10000.0, mid = 0.0;
	
	while (fabs(hi-lo) > EPS) {
		
		mid = (lo+hi)/2.0;
		
		if (simulate(mid)) {
			ans = mid;
			hi = mid;
		} else lo = mid;
		
	}
	
}

int main() {
	
	int d, c;
	char s[20];
	
	scanf("%d", &d);
	scanf("%s", s);
	scanf("%s", s);
	scanf("%d", &c);
	
	while (c) {
		
		value[0] = c;
		cant = 1;
		
		while (scanf("%d", &d), d) {
			
			scanf("%s", s);
			if (strcmp(s, "Fuel") == 0) {
				scanf("%s", s);
				scanf("%d", &c);
				value[cant] = c;
				dist[cant] = d;
				action[cant] = 'c';
			} else if (strcmp(s, "Leak") == 0) {
				dist[cant] = d;
				action[cant] = 'l';
			} if (strcmp(s, "Gas") == 0) {
				scanf("%s", s); 
				dist[cant] = d;
				action[cant] = 's';
			} if (strcmp(s, "Mechanic") == 0) {
				dist[cant] = d; 
				action[cant] = 'm';
			} if (strcmp(s, "Goal") == 0) {
				dist[cant] = d; 
				action[cant] = 'g';
			}
			
			cant++;
			
		}
		
		binary_search();
		
		printf("%.3lf\n", ans);
		
		scanf("%s", s);
		scanf("%s", s);
		scanf("%d", &c);
		
	}
	
	return 0;
} 
